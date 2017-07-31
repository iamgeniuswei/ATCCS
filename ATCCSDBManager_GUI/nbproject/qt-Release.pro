# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/GNU-Linux
TARGET = ATCCSDBManager_GUI
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
PKGCONFIG +=
QT = core gui widgets
SOURCES += main.cpp src/ATCCSDBMMainWindow.cpp src/ATCCSDBMStartup.cpp src/DBMAT60TablePanel.cpp src/DBMEMETablePanel.cpp src/DBMPublicTablePanel.cpp src/DBMStartupBtnPanel.cpp src/DBMStarupEditPanel.cpp src/DBMWBtnPanel.cpp src/DBMWEditPanel.cpp src/DBMWOutPanel.cpp src/DBMWOutputItem.cpp src/DBMWTitleBar.cpp
HEADERS += src/ATCCSDBMMainWindow.h src/ATCCSDBMStartup.h src/DBMAT60TablePanel.h src/DBMEMETablePanel.h src/DBMPublicTablePanel.h src/DBMStartupBtnPanel.h src/DBMStarupEditPanel.h src/DBMWBtnPanel.h src/DBMWEditPanel.h src/DBMWOutPanel.h src/DBMWOutputItem.h src/DBMWTitleBar.h
FORMS += src/ATCCSDBMMainWindow.ui src/ATCCSDBMStartup.ui src/DBMAT60TablePanel.ui src/DBMEMETablePanel.ui src/DBMPublicTablePanel.ui src/DBMStartupBtnPanel.ui src/DBMStarupEditPanel.ui src/DBMWBtnPanel.ui src/DBMWEditPanel.ui src/DBMWOutPanel.ui src/DBMWOutputItem.ui src/DBMWTitleBar.ui
RESOURCES += res/ATCCSDBManager.qrc
TRANSLATIONS += newtranslation.ts
OBJECTS_DIR = build/Release/GNU-Linux
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
