#include "atccsdatahandler.h"
#include <iostream>
ATCCSDataHandler::ATCCSDataHandler()
{

}

void ATCCSDataHandler::registerSuccessorHandler(unsigned int id, ATCCSDataHandler *handler)
{
    if(handler == nullptr)
    {
        std::cout << "the handler is empty"<<std::endl;
        return;
    }
    auto search = _successor.find(id);
    if(search != _successor.end())
    {
        std::cout << "the handler have already registered"<<std::endl;
        return;
    }
    _successor.insert(std::pair<unsigned int, ATCCSDataHandler*>(id, handler));
}

ATCCSDataHandler *ATCCSDataHandler::successorHandler(unsigned int id)
{
    auto search = _successor.find(id);
    if(search == _successor.end())
        return nullptr;
    ATCCSDataHandler *handler = search->second;
    return handler;
}
