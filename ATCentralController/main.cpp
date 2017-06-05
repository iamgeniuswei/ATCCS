/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: lenovo
 *
 * Created on May 12, 2017, 7:45 PM
 */

#include <cstdlib>

using namespace std;
#include <memory>
#include <iostream>
#include <thread>
#include "atccsdatareceiver.h"
#include "atccsdatadispatcher.h"
#include "atccsdataprocessor.h"
#include "src/ATCCLevel1DataProcessor.h"
#include "atccs_global.h"
#include "src/ATCCATController.h"
#include "atccs_public_define.h"
/*
 * 
 */
int main(int argc, char** argv) 
{
    std::cout << "-----------------AT Central Controller---------------------\n";
    try
    {
        //start a ATCCSDataReceiver
        std::shared_ptr<ATCCSDataReceiver> receiver(new ATCCSDataReceiver);

            receiver->setRecvAddress("192.168.0.115", 4747);
            std::thread th(&ATCCSDataReceiver::run, receiver);

        
        //start a ATCCSDataDispatcher.
        std::shared_ptr<ATCCSDataDispatcher> dispatcher(new ATCCSDataDispatcher);
        std::shared_ptr<ATCCATController> at60 (new ATCCATController(AT60));
        at60->setATControllerAddress("192.168.0.115", 4646);

            std::shared_ptr<ATCCSDataProcessor> processor(new ATCCSCCLevel1DataProcessor(dispatcher));
            dispatcher->setDataProcessor(processor);
            dispatcher->registerDeviceController(AT60, at60);
            std::thread th1(&ATCCSDataDispatcher::run, dispatcher);


            std::thread th2(&ATCCATController::handleControlData, at60);

        std::cin.get();
        
    }
    catch(std::exception &e)
    {
#ifdef OUTDEBUGINFO
        ATCCSDebugInfo(e);
#endif
    }
    

    
    return 0;
}

