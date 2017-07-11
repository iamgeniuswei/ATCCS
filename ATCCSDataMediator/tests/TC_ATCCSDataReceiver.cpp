/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   TC_ATCCSDataReceiver.cpp
 * Author: lenovo
 *
 * Created on 2017-6-27, 10:46:31
 */

#include "TC_ATCCSDataReceiver.h"
#include "atccsdatareceiver.h"
#include <thread>
#include <unistd.h>
#include "atccsdataqueue.h"
#include <iostream>


CPPUNIT_TEST_SUITE_REGISTRATION(TC_ATCCSDataReceiver);

TC_ATCCSDataReceiver::TC_ATCCSDataReceiver()
{
}

TC_ATCCSDataReceiver::~TC_ATCCSDataReceiver()
{
}

void TC_ATCCSDataReceiver::setUp()
{
    receiver = std::make_shared<ATCCSDataReceiver>();
}

void TC_ATCCSDataReceiver::tearDown()
{
}

void TC_ATCCSDataReceiver::testATCCSDataReceiver()
{

}

void TC_ATCCSDataReceiver::testRun()
{
    std::string ip("192.168.0.115");
    unsigned short port = 4747;
    CPPUNIT_ASSERT(receiver->setRecvAddress(ip, port) == 0);
    std::thread thread(&ATCCSDataReceiver::run, receiver);
    sleep(20);
    receiver->setStop(true);
    thread.join();
    ATCCSDataQueue *queue = ATCCSDataQueue::instance();
    std::cout << queue->size() << std::endl;
    CPPUNIT_ASSERT(queue->size() == 20);
}

void TC_ATCCSDataReceiver::testSetRecvAddress()
{

}

void TC_ATCCSDataReceiver::testSetRecvAddress2()
{

}

