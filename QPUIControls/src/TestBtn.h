/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestBtn.h
 * Author: lenovo
 *
 * Created on May 21, 2017, 3:45 PM
 */

#ifndef TESTBTN_H
#define TESTBTN_H
#include <QPushButton>
class TestBtn : public QPushButton
{
public:
    TestBtn(QWidget *parent = 0);
    TestBtn(const TestBtn& orig);
    virtual ~TestBtn();
private:
    QPixmap pixmap;
    protected:
    virtual void paintEvent(QPaintEvent* e);

            

};

#endif /* TESTBTN_H */

