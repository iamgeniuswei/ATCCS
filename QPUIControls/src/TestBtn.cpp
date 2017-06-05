/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestBtn.cpp
 * Author: lenovo
 * 
 * Created on May 21, 2017, 3:45 PM
 */

#include "TestBtn.h"
#include <QPainter>
TestBtn::TestBtn(QWidget *parent) : QPushButton(parent)
{
    pixmap.load(":/main/back");
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setFixedSize(pixmap.size());
}

TestBtn::TestBtn(const TestBtn& orig) {
}

TestBtn::~TestBtn() {
}

void TestBtn::paintEvent(QPaintEvent* e) 
{
//    QPushButton::paintEvent(e);
    QPainter painter(this);
    painter.drawPixmap(rect(), pixmap);
    painter.drawText(rect(), Qt::AlignCenter, "START");
}
