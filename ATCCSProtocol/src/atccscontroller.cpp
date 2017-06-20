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
}

/**
 * push a shared_ptr of ATCCSData into fifo queue.
 * @param data
 * @return void
 * @access public
 */
void ATCCSController::pushControlData(std::shared_ptr<ATCCSData> data)
{
    _fifoQueue.push(data);
}

/**
 * clear the fifo queue.
 * @return void
 * @access public
 */
void ATCCSController::clearControlData()
{
    while (_fifoQueue.size() > 0) 
    {
        _fifoQueue.wait_and_pop();
    }
}

/**
 * fetch a share_ptr of ATCCSData from fifo queue.
 * @exception std::exception
 * @return std::shared_ptr<ATCCSData>
 * @access protected
 */
std::shared_ptr<ATCCSData> ATCCSController::popControlData()
{
    std::shared_ptr<ATCCSData> temp = _fifoQueue.wait_and_pop();
    return temp;
}
