#ifndef ICONEDITOR_H
#define ICONEDITOR_H

#include <QWidget>
#include <QColor>
#include <QImage>

class IconEditor : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor penColor READ penColor WRITE setPenColor)
    Q_PROPERTY(QImage iconImage READ iconImage WRITE setIconImage)
    Q_PROPERTY(int zoomFactor READ zoomFactor WRITE setZoomFactor)
public:
    // Q_PROPERTY will be shown in property window, they need to list under Q_OBJECT
    explicit IconEditor(QWidget *parent = 0);

    void setPenColor(const QColor &newColor);
    QColor penColor() const {return curColor;}
    void setZoomFactor(int newZoom);
    int zoomFactor() const {return zoom;}
    void setIconImage(const QImage &newImage);
    QImage iconImage() const {return image;}
    QSize sizeHint() const;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);

private:
    void setImagePixel(const QPoint &pos, bool opaque);
    QRect pixelRect(int i, int j) const;
    bool isZoomedIn() const{ return (zoom >=3 );}

    QColor curColor;
    QImage image;
    int zoom;
};

#endif // ICONEDITOR_H