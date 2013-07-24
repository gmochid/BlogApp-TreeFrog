TARGET = controller
TEMPLATE = lib
CONFIG += shared x86_64
QT += network sql xml
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers ../models
DEPENDPATH  += ../helpers ../models
LIBS += -L../lib -lhelper -lmodel

include(../appbase.pri)

HEADERS += applicationcontroller.h
SOURCES += applicationcontroller.cpp
HEADERS += blogcontroller.h
SOURCES += blogcontroller.cpp
HEADERS += postcontroller.h
SOURCES += postcontroller.cpp
HEADERS += usercontroller.h
SOURCES += usercontroller.cpp
HEADERS += sessioncontroller.h
SOURCES += sessioncontroller.cpp
HEADERS += admincontroller.h
SOURCES += admincontroller.cpp
