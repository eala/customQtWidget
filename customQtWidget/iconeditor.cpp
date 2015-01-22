#include "iconeditor.h"
#include <QPainter>
#include <QPaintEvent>
#include <QRegion>

IconEditor::IconEditor(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);  // horizontal & vertical policy

    curColor = Qt::black;
    const int SQUARE_PER_PIXEL = 8;
    zoom = SQUARE_PER_PIXEL;

    const int PIXEL_SIZE = 16;
    image = QImage(PIXEL_SIZE, PIXEL_SIZE, QImage::Format_ARGB32);  // what a magic number
    image.fill(qRgba(0, 0, 0, 0));
}

QSize IconEditor::sizeHint() const{
    QSize size = zoom * image.size();
    if(isZoomedIn())
        size+= QSize(1, 1);
    return size;
}

void IconEditor::setPenColor(const QColor &newColor){
    curColor = newColor;
}

void IconEditor::setIconImage(const QImage &newImage){
    if(newImage != image){
        image = newImage.convertToFormat(QImage::Format_ARGB32);
        update();
        updateGeometry();
    }
}

void IconEditor::setZoomFactor(int newZoom){
    newZoom = std::max(1, newZoom);

    if(newZoom != zoom){
        zoom = newZoom;
        update();
        updateGeometry();
    }
}

void IconEditor::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    if(isZoomedIn()){  // draw grid
        painter.setPen(palette().foreground().color());
        // horizontal line
        for(int i=0; i<= image.width(); ++i)
            painter.drawLine(zoom*i, 0, zoom*i, zoom*image.height());
        // vertical line
        for(int j=0; j<= image.height(); ++j)
            painter.drawLine(0, zoom*j, zoom*image.width(), zoom*j);
    }

    for(int i=0; i< image.width(); ++i){
        for(int j=0; j< image.height(); ++j){
            QRect rect = pixelRect(i, j);
            if(event->region().intersects(rect)){
                QColor color = QColor::fromRgba(image.pixel(i, j));
                if(color.alpha() < 255)
                    painter.fillRect(rect, Qt::white);
                painter.fillRect(rect, color);
            }
        }
    }
}

QRect IconEditor::pixelRect(int i, int j) const{
    return (isZoomedIn())?
            QRect(zoom*i+1, zoom*j+1, zoom-1, zoom-1) :     // avoid overlapping with grid
            QRect(zoom*i, zoom*j, zoom, zoom);
}

void IconEditor::mousePressEvent(QMouseEvent *event){
    if(Qt::LeftButton == event->button()){
        setImagePixel(event->pos(), true);
    }else if(Qt::RightButton == event->button()){
        setImagePixel(event->pos(), false); // clear pixel
    }
}

void IconEditor::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons() & Qt::LeftButton){
        setImagePixel(event->pos(), true);
    }else if(event->buttons() & Qt::RightButton){
        setImagePixel(event->pos(), false);
    }
}

void IconEditor::setImagePixel(const QPoint &pos, bool opaque){
    int i = pos.x() / zoom;
    int j = pos.y() / zoom;

    if(image.rect().contains(i, j)){
        image.setPixel(i, j, (opaque)? penColor().rgba() : qRgba(0, 0, 0, 0));
        update(pixelRect(i, j));
    }
}
