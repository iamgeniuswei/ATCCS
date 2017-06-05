#ifndef ATCCSDATAHANDLER_H
#define ATCCSDATAHANDLER_H

#include <memory>
#include "atccs_global.h"
#include <map>
class ATCCSData;
class ATCCSDataHandler
{
public:
    ATCCSDataHandler();
    virtual void processData(std::shared_ptr<ATCCSData> data) = 0;
    void registerSuccessorHandler(unsigned int id, ATCCSDataHandler* handler = nullptr);
    ATCCSDataHandler* successorHandler(unsigned int id);
private:
    unsigned int _id;
    std::map<unsigned int, ATCCSDataHandler*> _successor;
};

#endif // ATCCSDATAHANDLER_H
