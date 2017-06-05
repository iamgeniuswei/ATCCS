#ifndef ATCCSDATAQUEUE_H
#define ATCCSDATAQUEUE_H

#include "atccsqueue.h"
class ATCCSData;
class ATCCSDataQueue : public ATCCSQueue<std::shared_ptr<ATCCSData>>
{
private:
    explicit ATCCSDataQueue();
    ATCCSDataQueue(const ATCCSDataQueue&) = delete;
    ATCCSDataQueue& operator=(const ATCCSDataQueue&) = delete;
    static ATCCSDataQueue *_instance;
    class ATCCSDataQueueGarbo
    {
    public:
        ~ATCCSDataQueueGarbo()
        {
            if(_instance != nullptr)
            {
                delete _instance;
                _instance = nullptr;
            }
        }
    };
    static ATCCSDataQueueGarbo _Garbo;

public:
    static ATCCSDataQueue *instance();
    ~ATCCSDataQueue();
};

#endif // ATCCSDATAQUEUE_H
