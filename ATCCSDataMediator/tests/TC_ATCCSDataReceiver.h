/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   TC_ATCCSDataReceiver.h
 * Author: lenovo
 *
 * Created on 2017-6-27, 10:46:30
 */

#ifndef TC_ATCCSDATARECEIVER_H
#define TC_ATCCSDATARECEIVER_H

#include <cppunit/extensions/HelperMacros.h>
#include <memory>
class ATCCSDataReceiver;
class TC_ATCCSDataReceiver : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE(TC_ATCCSDataReceiver);

    CPPUNIT_TEST(testATCCSDataReceiver);
    CPPUNIT_TEST(testRun);
    CPPUNIT_TEST(testSetRecvAddress);
    CPPUNIT_TEST(testSetRecvAddress2);

    CPPUNIT_TEST_SUITE_END();

public:
    TC_ATCCSDataReceiver();
    virtual ~TC_ATCCSDataReceiver();
    void setUp();
    void tearDown();

private:
    void testATCCSDataReceiver();
    void testRun();
    void testSetRecvAddress();
    void testSetRecvAddress2();
    std::shared_ptr<ATCCSDataReceiver> receiver;

};

#endif /* TC_ATCCSDATARECEIVER_H */

