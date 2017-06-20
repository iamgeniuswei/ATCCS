#ifndef ATCCSONLINE_H
#define ATCCSONLINE_H

#include <mutex>
class ATCCSOnline
{
public:
    explicit ATCCSOnline();
    static unsigned int interval();
    static void setInterval(unsigned int interval = 0);

    bool online() const;
    void setOnline(bool online, unsigned int time);

private:
    static unsigned int _interval;
    unsigned int _lastTime = 0;
    mutable bool _online = false;
    mutable std::mutex _onlineLock;
};

#endif // ATCCSONLINE_H
