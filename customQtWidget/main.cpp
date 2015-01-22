#include "widget.h"
#include <QApplication>
#include "hexspinbox.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //w.show();
    HexSpinBox hexBox;
    hexBox.show();

    return a.exec();
}
