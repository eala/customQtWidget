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
    iconeditor.cpp\
    iconeditorplugin.cpp

HEADERS +=\
    iconeditor.h\
    iconeditorplugin.h

OTHER_FILES += iconeditor.json

DISTFILES +=\
    iconeditor.json
