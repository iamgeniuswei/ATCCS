/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newsimpletest.cpp
 * Author: lenovo
 *
 * Created on May 5, 2017, 8:46 PM
 */

#include <stdlib.h>
#include <iostream>
#include "src/atccsdatareceiver.h"

/*
 * Simple C++ Test Suite
 */

void testSetStop() {
    bool stop = false;
    ATCCSDataReceiver aTCCSDataReceiver;
    aTCCSDataReceiver.setStop(false);
    std::cout << aTCCSDataReceiver.stop() <<std::endl;
    if (aTCCSDataReceiver.stop() == 1 /*check result*/) 
    {
        std::cout << "%TEST_FAILED% time=0 testname=testSetStop (newsimpletest) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testSetStop (newsimpletest)" << std::endl;
    testSetStop();
    std::cout << "%TEST_FINISHED% time=0 testSetStop (newsimpletest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

