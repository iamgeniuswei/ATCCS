#ifndef ATCCSCONTROLLERMANAGER_H
#define ATCCSCONTROLLERMANAGER_H

#include <map>
#include <memory>
#include <iostream>
template <typename T>
class ATCCSMapManager
{
public:
    explicit ATCCSMapManager()
    {

    }
    ~ATCCSMapManager()
    {
        _controllers.clear();
        std::cout << "~ATCCSMapManager\n";
    }

    bool registerController(unsigned int id, std::shared_ptr<T> controller = nullptr)
    {
        if(controller == nullptr)
        {            
            return false;
        }
        auto search = _controllers.find(id);
        if(search != _controllers.end())
        {            
            return false;
        }
        _controllers.insert(std::pair<unsigned int, std::shared_ptr<T>>(id, controller));
    }

    std::shared_ptr<T> controller(unsigned int id)
    {
        auto search = _controllers.find(id);
        if(search == _controllers.end())
        {            
            return nullptr;
        }

        std::shared_ptr<T> temp = search->second;
        return temp;
    }

private:
    std::map<unsigned int, std::shared_ptr<T>> _controllers;
};

#endif // ATCCSCONTROLLERMANAGER_H
