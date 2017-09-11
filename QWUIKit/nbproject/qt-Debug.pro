# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = lib
DESTDIR = dist/Debug/GNU-Linux
TARGET = QWUIKit
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += dll debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += src/QWButtonPanel.cpp src/QWComboItem.cpp src/QWDBAddressPanel.cpp src/QWFramelessWindow.cpp src/QWLocalAddressPanel.cpp src/QWOutputDefaultItem.cpp src/QWOutputPanel.cpp src/QWPopupTitleBar.cpp src/QWPopupWindowTitleBar.cpp src/QWTitleBar.cpp src/QWUIInitializer.cpp src/qwtimeline.cpp src/qwtimelinewidget.cpp
HEADERS += src/QWButtonPanel.h src/QWComboItem.h src/QWDBAddressPanel.h src/QWFramelessWindow.h src/QWLocalAddressPanel.h src/QWOutputDefaultItem.h src/QWOutputPanel.h src/QWPopupTitleBar.h src/QWPopupWindowTitleBar.h src/QWTitleBar.h src/QWUIInitializer.h src/private/qwtitlebar_p.h src/qwtimeline.h src/qwtimelinewidget.h
FORMS += src/QWButtonPanel.ui src/QWComboItem.ui src/QWDBAddressPanel.ui src/QWLocalAddressPanel.ui src/QWOutputDefaultItem.ui src/QWOutputPanel.ui src/QWPopupTitleBar.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux
MOC_DIR = moc
RCC_DIR = rcc
UI_DIR = ui
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
