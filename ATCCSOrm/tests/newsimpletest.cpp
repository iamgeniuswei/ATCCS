/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newsimpletest.cpp
 * Author: lenovo
 *
 * Created on May 5, 2017, 9:24 PM
 */

#include <stdlib.h>
#include <iostream>
#include "src/atccspublicstatus.h"

/*
 * Simple C++ Test Suite
 */

void testCurstatus() {
    atccspublicstatus aTCCSPublicStatus;
    unsigned int result = aTCCSPublicStatus.curstatus();
    if (result != 0 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testCurstatus (newsimpletest) message=error message sample" << std::endl;
    }
}

void testLastStatus() {
    atccspublicstatus aTCCSPublicStatus;
    unsigned int result = aTCCSPublicStatus.lastStatus();
    if (result != 0 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testLastStatus (newsimpletest) message=error message sample" << std::endl;
    }
}

void testWarning() {
    atccspublicstatus aTCCSPublicStatus;
    unsigned int result = aTCCSPublicStatus.warning();
    if (result != 0 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testWarning (newsimpletest) message=error message sample" << std::endl;
    }
}

void testError() {
    atccspublicstatus aTCCSPublicStatus;
    unsigned int result = aTCCSPublicStatus.error();
    if (result != 0 /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testError (newsimpletest) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testCurstatus (newsimpletest)" << std::endl;
    testCurstatus();
    std::cout << "%TEST_FINISHED% time=0 testCurstatus (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testLastStatus (newsimpletest)" << std::endl;
    testLastStatus();
    std::cout << "%TEST_FINISHED% time=0 testLastStatus (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testWarning (newsimpletest)" << std::endl;
    testWarning();
    std::cout << "%TEST_FINISHED% time=0 testWarning (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testError (newsimpletest)" << std::endl;
    testError();
    std::cout << "%TEST_FINISHED% time=0 testError (newsimpletest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

