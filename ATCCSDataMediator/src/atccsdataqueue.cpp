#include "atccsdataqueue.h"
#include <iostream>
ATCCSDataQueue *ATCCSDataQueue::_instance = nullptr;
ATCCSDataQueue::ATCCSDataQueueGarbo ATCCSDataQueue::_Garbo;
ATCCSDataQueue::ATCCSDataQueue():ATCCSQueue()
{

}

ATCCSDataQueue *ATCCSDataQueue::instance()
{
    if(_instance == nullptr)
    {
        if(_instance == nullptr)
        {
            _instance = new (std::nothrow) ATCCSDataQueue;
        }
    }
    return _instance;
}

ATCCSDataQueue::~ATCCSDataQueue()
{
    try
    {
        std::lock_guard<std::mutex> lk(_queueLock);
        while (_dataQueue.size() > 0)
        {
            _dataQueue.pop();
        }
    }
    catch(std::exception &e)
    {
#ifdef OUTERRORINFO
        std::cout << e.what() << std::endl;
#endif
    }
#ifdef OUTDEBUGINFO
    std::cout << "~ATCCSDataQueue\n";
#endif
}
