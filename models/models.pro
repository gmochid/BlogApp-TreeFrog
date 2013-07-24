TARGET = model
TEMPLATE = lib
CONFIG += shared x86_64
QT += sql
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers sqlobjects
DEPENDPATH  += ../helpers sqlobjects
LIBS += -L../lib -lhelper

include(../appbase.pri)

HEADERS += sqlobjects/blogobject.h
HEADERS += blog.h
SOURCES += blog.cpp
HEADERS += sqlobjects/postobject.h
HEADERS += post.h
SOURCES += post.cpp
HEADERS += sqlobjects/userobject.h
HEADERS += user.h
SOURCES += user.cpp
HEADERS += sqlobjects/adminobject.h
HEADERS += admin.h
SOURCES += admin.cpp
