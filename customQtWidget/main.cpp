#include "widget.h"
#include <QApplication>
#include "hexspinbox.h"
#include "iconeditor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    HexSpinBox hexBox;
    hexBox.show();

    IconEditor iconEditor;
    iconEditor.show();

    return a.exec();
}
