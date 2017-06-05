#include "atccsonline.h"
#include <ctime>
#include <iostream>
unsigned int ATCCSOnline::_interval = 60;
ATCCSOnline::ATCCSOnline()
{

}

ATCCSOnline::~ATCCSOnline()
{
    
}

unsigned int ATCCSOnline::interval()
{
    return _interval;
}

void ATCCSOnline::setInterval(unsigned int interval)
{
    _interval = interval;
}

bool ATCCSOnline::online() const
{
    std::lock_guard<std::mutex> lk(_onlineLock);
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    if((now - _lastTime) > _interval)
        return false;
    return _online;
}

void ATCCSOnline::setOnline(bool online, unsigned int time)
{
    std::lock_guard<std::mutex> lk(_onlineLock);
    _lastTime = time;
    _online = online;
}
