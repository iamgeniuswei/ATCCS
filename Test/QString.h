/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QString.h
 * Author: lenovo
 *
 * Created on 2017年6月23日, 上午9:35
 */

#ifndef QSTRING_H
#define QSTRING_H

class QString
{
public:
    QString();
    QString(const QString& orig);
    QString(QString&& orig);
    QString& operator=(const QString& orig);
    QString& operator=(QString&& orig);
    virtual ~QString();

protected:

private:
    char *_data;

};

#endif /* QSTRING_H */

