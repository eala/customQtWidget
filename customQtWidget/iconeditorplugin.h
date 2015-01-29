#ifndef ICONEDITORPLUGIN_H
#define ICONEDITORPLUGIN_H

#include <QObject>
#include <QDesignerCustomWidgetInterface>

// sample http://doc.qt.io/qt-5/qtdesigner-customwidgetplugin-example.html
class IconEditorPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetInterface)
    Q_PLUGIN_METADATA(IID "com.CustomIconEditorPlugin" FILE "iconeditor.json")
public:
    explicit IconEditorPlugin(QObject *parent = 0);

    bool isContainer() const;
    bool isInitialized() const;
    QIcon icon() const;
    QString domXml() const;
    QString group() const;
    QString includeFile() const;
    QString name() const;
    QString toolTip() const;
    QString whatsThis() const;

    QWidget *createWidget(QWidget *parent);
    void initialize(QDesignerFormEditorInterface *core);

private:
    bool initialized;
};

#endif // ICONEDITORPLUGIN_H
