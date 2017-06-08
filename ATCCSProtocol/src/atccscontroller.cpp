#include "atccscontroller.h"
#include <iostream>

ATCCSController::ATCCSController()
{
    
}

ATCCSController::~ATCCSController()
{
    while (_fifoQueue.size() > 0) 
    {
        _fifoQueue.wait_and_pop();
    }
    std::cout << "~ATCCSController\n";
}

/**
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------
 * push Control Data into first in first out queue.
 * -----------------------------------------------------------------------------
 * @param:  data
 * @return: none
 * -----------------------------------------------------------------------------
 * @author: Geniuswei
 * @date:   2017-05-24
 * -----------------------------------------------------------------------------
 */
void ATCCSController::pushControlData(std::shared_ptr<ATCCSData> data)
{
    _fifoQueue.push(data);
}

/**
 * -----------------------------------------------------------------------------
 * clear all Control Data.
 * -----------------------------------------------------------------------------
 * @param:  none
 * @return: none
 * -----------------------------------------------------------------------------
 * @author: Geniuswei
 * @date:   2017-05-24
 * -----------------------------------------------------------------------------
 */
void ATCCSController::clearControlData()
{
    while (_fifoQueue.size() > 0) 
    {
        _fifoQueue.wait_and_pop();
    }
}

std::shared_ptr<ATCCSData> ATCCSController::popControlData()
{
    std::shared_ptr<ATCCSData> temp = _fifoQueue.wait_and_pop();
    return temp;
}
