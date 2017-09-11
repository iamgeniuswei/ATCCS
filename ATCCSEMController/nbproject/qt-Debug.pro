# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux
TARGET = ATCCSEMController
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
INCLUDEPATH += ../ATCCSEMWindow/src ../ATCCSEMWindow/ui ../QWUIKit/src ../ATCCSEMCore/src ../ATCCSProtocol/src ../ATCCSUtility/src 
LIBS += -Wl,-rpath,../ATCCSEMWindow/dist/Debug/GNU-Linux ../ATCCSEMWindow/dist/Debug/GNU-Linux/libATCCSEMWindow.so.1.0.0 -Wl,-rpath,../QWUIKit/dist/Debug/GNU-Linux ../QWUIKit/dist/Debug/GNU-Linux/libQWUIKit.so.1.0.0 -Wl,-rpath,../ATCCSEMCore/dist/Debug/GNU-Linux ../ATCCSEMCore/dist/Debug/GNU-Linux/libATCCSEMCore.so -Wl,-rpath,../ATCCSProtocol/dist/Debug/GNU-Linux ../ATCCSProtocol/dist/Debug/GNU-Linux/libATCCSProtocol.so -Wl,-rpath,../ATCCSUtility/dist/Release/GNU-Linux ../ATCCSUtility/dist/Release/GNU-Linux/libATCCSUtility.so  -Wl,-rpath,dist/Debug/GNU-Linux 
equals(QT_MAJOR_VERSION, 4) {
QMAKE_CXXFLAGS += -std=c++11
}
equals(QT_MAJOR_VERSION, 5) {
CONFIG += c++11
}
