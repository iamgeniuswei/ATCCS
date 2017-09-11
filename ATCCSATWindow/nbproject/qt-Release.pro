# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = lib
DESTDIR = dist/Release/GNU-Linux
TARGET = ATCCSATWindow
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += dll release 
PKGCONFIG +=
QT = core gui widgets
SOURCES += src/ATCDevicePanel.cpp src/ATCDisplayArea.cpp src/ATCMainWindow.cpp src/ATCSelectionPanel.cpp src/ATCSelectionWindow.cpp src/ATCSettingPanel.cpp src/ATCSettingWindow.cpp src/ATCTitleBar.cpp
HEADERS += src/ATCDevicePanel.h src/ATCDisplayArea.h src/ATCMainWindow.h src/ATCSelectionPanel.h src/ATCSelectionWindow.h src/ATCSettingPanel.h src/ATCSettingWindow.h src/ATCTitleBar.h
FORMS += ATCSelectionWindow.ui src/ATCDevicePanel.ui src/ATCDisplayArea.ui src/ATCMainWindow.ui src/ATCSelectionPanel.ui src/ATCSettingPanel.ui src/ATCSettingWindow.ui src/ATCTitleBar.ui
RESOURCES += res/ATCCSATWindow.qrc
TRANSLATIONS +=
OBJECTS_DIR = build/Release/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
