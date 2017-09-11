/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QWUIInitializer.h
 * Author: lenovo
 *
 * Created on August 1, 2017, 8:48 AM
 */

#ifndef QWUIINITIALIZER_H
#define QWUIINITIALIZER_H

class QWUIInitializer
{
public:
    QWUIInitializer();
    QWUIInitializer(const QWUIInitializer& orig) = delete;
    QWUIInitializer(const QWUIInitializer&& orig) = delete;
    QWUIInitializer& operator=(const QWUIInitializer& orig) = delete;
    QWUIInitializer& operator=(const QWUIInitializer&& orig) = delete;
    virtual ~QWUIInitializer();
protected:
    virtual void initializeUI(){}
    virtual void initializeSignal(){}
private:

};

#endif /* QWUIINITIALIZER_H */

