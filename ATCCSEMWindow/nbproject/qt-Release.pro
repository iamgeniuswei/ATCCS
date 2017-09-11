# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = lib
DESTDIR = dist/Release/GNU-Linux
TARGET = ATCCSEMWindow
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += dll release 
PKGCONFIG +=
QT = core gui widgets
SOURCES += src/ATCCSEMDisplayArea.cpp src/ATCCSEMSettingWindow.cpp src/ATCCSEMTitleBar.cpp src/ATCCSEMWindow.cpp src/EMASCDataPanel.cpp src/EMCSDataPanel.cpp src/EMDBAddressPanel.cpp src/EMDisplaySetPanel.cpp src/EMLocalAddressPanel.cpp src/EMSQMPanel.cpp src/EMSettingTilteBar.cpp src/EMSingleDataPanel.cpp src/EMWSDataPanel.cpp
HEADERS += src/ATCCSEMDisplayArea.h src/ATCCSEMSettingWindow.h src/ATCCSEMTitleBar.h src/ATCCSEMWindow.h src/EMASCDataPanel.h src/EMCSDataPanel.h src/EMDBAddressPanel.h src/EMDisplaySetPanel.h src/EMLocalAddressPanel.h src/EMSQMPanel.h src/EMSettingTilteBar.h src/EMSingleDataPanel.h src/EMWSDataPanel.h
FORMS += src/ATCCSEMDisplayArea.ui src/ATCCSEMSettingWindow.ui src/ATCCSEMTitleBar.ui src/ATCCSEMWindow.ui src/EMASCDataPanel.ui src/EMCSDataPanel.ui src/EMDBAddressPanel.ui src/EMDisplaySetPanel.ui src/EMLocalAddressPanel.ui src/EMSQMPanel.ui src/EMSettingTilteBar.ui src/EMSingleDataPanel.ui src/EMWSDataPanel.ui
RESOURCES += res/ATCCSEMWindow.qrc
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