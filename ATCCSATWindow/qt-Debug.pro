# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = lib
DESTDIR = dist/Debug/GNU-Linux
TARGET = ATCCSATWindow
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += dll debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += src/ATCDevicePanel.cpp src/ATCTitleBar.cpp
HEADERS += src/ATCDevicePanel.h src/ATCTitleBar.h
FORMS += src/ATCDevicePanel.ui src/ATCTitleBar.ui
RESOURCES += res/ATCCSATWindow.qrc
TRANSLATIONS += res/qss/ATCCSATWindow.ts
OBJECTS_DIR = build/Debug/GNU-Linux
MOC_DIR = moc
RCC_DIR = rcc
UI_DIR = ui
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
