# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux
TARGET = ATCCSATController
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += main.cpp
HEADERS +=
FORMS +=
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += ../ATCCSATWindow/src ../ATCCSATWindow/ui ../QWUIKit/src ../QWUIKit/ui 
LIBS += -Wl,-rpath,../ATCCSATWindow/dist/Debug/GNU-Linux ../ATCCSATWindow/dist/Debug/GNU-Linux/libATCCSATWindow.so.1.0.0 -Wl,-rpath,../QWUIKit/dist/Debug/GNU-Linux ../QWUIKit/dist/Debug/GNU-Linux/libQWUIKit.so.1.0.0  
