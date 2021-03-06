#ifndef ATCCSQUEUE_H
#define ATCCSQUEUE_H
#include "atccs_global.h"
#include <queue>
#include <memory>
#ifdef C11
#include <mutex>
#include <condition_variable>
#endif
#include <iostream>
template <typename T>
class ATCCSQueue
{
public:
    explicit ATCCSQueue()
    {

    }
    virtual ~ATCCSQueue()
    {
        std::cout << "~ATCCSQueue()\n";
    }

    ATCCSQueue(ATCCSQueue const& other)
    {
#ifdef C11
        std::lock_guard<std::mutex> lk(other._queueLock);
        _dataQueue = other._dataQueue;
#endif
    }
    void push(T new_value)
    {
#ifdef C11
        std::lock_guard<std::mutex> lk(_queueLock);
        _dataQueue.push(new_value);
        _dataCond.notify_one();
#endif

    }

    void wait_and_pop(T& value)
    {
#ifdef C11
        std::unique_lock<std::mutex> lk(_queueLock);
//        _dataCond.wait_for(lk, std::chrono::seconds(1), [this]{return !_dataQueue.empty();})
        _dataCond.wait(lk, [this]{return !_dataQueue.empty();});

        value = _dataQueue.front();
        _dataQueue.pop();
#endif
    }

    T wait_and_pop()
    {
#ifdef C11
        std::unique_lock<std::mutex> lk(_queueLock);
        _dataCond.wait_for(lk, std::chrono::seconds(1), [this]{return !_dataQueue.empty();});
//        _dataCond.wait(lk, [this]{return !_dataQueue.empty();});
        if(_dataQueue.empty())
            return nullptr;
        T value = _dataQueue.front();
        _dataQueue.pop();
        return value;
#endif
    }

    bool try_pop(T& value)
    {
#ifdef C11
        std::lock_guard<std::mutex> lk(_queueLock);
        if(_dataQueue.empty())
            return false;
        value = _dataQueue.front();
        _dataQueue.pop();
        return true;
#endif
    }

    std::shared_ptr<T> try_pop()
    {
#ifdef C11
        std::lock_guard<std::mutex> lk(_queueLock);
        if(_dataQueue.empty())
            return std::shared_ptr<T>();
        std::shared_ptr<T> value(std::make_shared<T>(_dataQueue.front()));
        _dataQueue.pop();
        return value;
#endif
    }

    bool empty() const
    {
#ifdef C11
        std::lock_guard<std::mutex> lk(_queueLock);
        return _dataQueue.empty();
#endif
    }
    size_t size() const
    {
#ifdef C11
        std::lock_guard<std::mutex> lk(_queueLock);
        return _dataQueue.size();
#endif
    }


protected:
#ifdef C11
    mutable std::mutex _queueLock;
    std::condition_variable _dataCond;
#endif
    std::queue<T> _dataQueue;
};

#endif // ATCCSQUEUE_H
