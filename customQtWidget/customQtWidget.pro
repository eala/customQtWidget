#-------------------------------------------------
#
# Project created by QtCreator 2015-01-20T22:57:46
#
#-------------------------------------------------

QT += designer widgets

TARGET = customQtWidget
TEMPLATE = lib

CONFIG += plugin release

SOURCES +=\
    #hexspinbox.cpp \
    iconeditor.cpp \
    iconeditorplugin.cpp \
    #form.cpp

HEADERS  += \
    #hexspinbox.h \
    iconeditor.h \
    iconeditorplugin.h \
    #form.h

#FORMS += \
    #form.ui

OTHER_FILES += iconeditor.json

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS += target

DISTFILES += \
    iconeditor.json
