# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux
TARGET = QtTest
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += main.cpp nbproject/newForm1.cpp nbproject/src/newForm1.cpp newForm.cpp
HEADERS += nbproject/newForm1.h nbproject/src/newForm1.h newForm.h
FORMS += nbproject/newForm1.ui nbproject/src/newForm1.ui newForm.ui
RESOURCES +=
TRANSLATIONS += nbproject/newtranslation1.ts newtranslation.ts
OBJECTS_DIR = build/Debug/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
equals(QT_MAJOR_VERSION, 4) {
QMAKE_CXXFLAGS += -std=c++11
}
equals(QT_MAJOR_VERSION, 5) {
CONFIG += c++11
}
