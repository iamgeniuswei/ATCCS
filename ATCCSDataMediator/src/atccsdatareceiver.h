#ifndef ATCADATARECEIVER_H
#define ATCADATARECEIVER_H
#include "atccsthread.h"
#include <memory>
class QPUdpSocket;
class ATCCSDataQueue;
class ATCCSAddress;
/**
 * ---------------------------------------------
 * ATCCSDataReceiver is a Thread Class and 
 * executes in a new thread. The class allows 
 * users to receive udp datagram on the 
 * appointed ip and port. 
 * ---------------------------------------------
 * @author: Geniuswei
 * @date:   2017-05-24
 * ---------------------------------------------
 */
class ATCCSDataReceiver : public ATCCSThread
{    
public:
    enum RETCODE
    {
        FAIL = -1,
        SUCCESS = 0
    };
public:
    explicit ATCCSDataReceiver();
    ~ATCCSDataReceiver();
    void run() override;
    int setRecvAddress(std::shared_ptr<ATCCSAddress> address = nullptr);
    int setRecvAddress(const std::string &ip, unsigned short port);   


private:
    std::shared_ptr<QPUdpSocket> _recvSocket = nullptr;
    ATCCSDataQueue *_dataQueue = nullptr;
    bool isReadyToRecv = false;
    static const int BUFFER_SIZE = 4096;
};

#endif // ATCADATARECEIVER_H
