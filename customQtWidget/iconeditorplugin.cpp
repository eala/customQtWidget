#include "iconeditorplugin.h"
#include "iconeditor.h"

IconEditorPlugin::IconEditorPlugin(QObject *parent) : QObject(parent)
{
    initialized = false;
}

void IconEditorPlugin::initialize(QDesignerFormEditorInterface * /*core*/){
    if(initialized)
        return;
    initialized = true;
}

bool IconEditorPlugin::isInitialized() const{
    return initialized;
}

QString IconEditorPlugin::name() const{
    return "IconEditor";
}

QString IconEditorPlugin::includeFile() const{
    return "iconeditor.h";
}

QString IconEditorPlugin::group() const{
    return tr("Image Manipulation Widgets");
}

QIcon IconEditorPlugin::icon() const{
    //return QIcon(":/images/iconeditor.png");
    return QIcon();
}

QString IconEditorPlugin::toolTip() const{
    return tr("An icon editor widget");
}

QString IconEditorPlugin::whatsThis() const{
    return tr("This widget is presented in Chapter 5 of <i>C++ GUI "
              "Programming with Qt 4</i> as an example of a custom Qt"
              "widget.");
}

bool IconEditorPlugin::isContainer() const{
    return false;
}

QString IconEditorPlugin::domXml() const
{
    return "<ui language=\"c++\">\n"
           " <widget class=\"IconEditor\" name=\"IconEditor\">\n"
           "  <property name=\"geometry\">\n"
           "   <rect>\n"
           "    <x>0</x>\n"
           "    <y>0</y>\n"
           "    <width>100</width>\n"
           "    <height>100</height>\n"
           "   </rect>\n"
           "  </property>\n"
           "  <property name=\"toolTip\" >\n"
           "   <string>An icon editor widget</string>\n"
           "  </property>\n"
           "  <property name=\"whatsThis\" >\n"
           "   <string>This widget is presented in Chapter 5 of C++ GUI Programming with Qt 4 as an example of a custom Qt widget.</string>\n"
           "  </property>\n"
           " </widget>\n"
           "</ui>\n";
}

QWidget *IconEditorPlugin::createWidget(QWidget *parent){
    return new IconEditor(parent);
}

// It should be added for all plugin
#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
    Q_PLUGIN_METADATA(IID "IconEditorPlugin" FILE "iconeditorplugin.h")
#else
    Q_EXPORT_PLUGIN2(iconeditorplugin, IconEditorPlugin)
#endif

