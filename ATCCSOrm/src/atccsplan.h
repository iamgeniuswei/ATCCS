#ifndef ATCCSPLAN_H
#define ATCCSPLAN_H
#include <cstddef>
#include <string>
#include <memory>
#include <odb/core.hxx>

class ATCCSData;


/**
 * @brief atccsplan is the base class of AT's plan
 */
#pragma db object
class atccsplan
{
public:
    enum RESULT_PLAN
    {
        RESULT_PLANERROR,
        RESULT_EXECUTING,
        RESULT_ABORTED,
        RESULT_SUCCESS
    };
    explicit atccsplan();
    atccsplan(const atccsplan&) = delete;
    atccsplan& operator =(const atccsplan&) = delete;
    ~atccsplan();
    virtual unsigned int persistPlan(){return 0;}
    virtual void persistPlanResult(){}
    unsigned int setPlan(std::shared_ptr<ATCCSData> data = nullptr);
    double delayTime() const;
    double declination() const;
    double rightAscension() const;
    double exposureTime() const;
    unsigned int readout() const;
    unsigned int bin() const;
    unsigned int gain() const;
    unsigned int exposureCount() const;
    unsigned int epoch() const;
    unsigned int type() const;
    unsigned int at() const;
    unsigned int percent() const;
    unsigned int result() const;
    unsigned int msec() const;
    unsigned int sec() const;
    std::string filter() const;
    std::string target() const;
    std::string project() const;
    std::string user() const;
    unsigned int id() const;
    unsigned int tag() const;

private:
    friend class odb::access;
#pragma db id auto
    unsigned int _id = 0;
    unsigned int _tag = 0;
    std::string _user;
    std::string _project;
    std::string _target;
    std::string _filter;
    unsigned int _sec = 0;
    unsigned int _msec = 0;
    unsigned int _result = 0;
    unsigned int _percent = 0;
    unsigned int _at = 0;
    unsigned int _type = 0;
    unsigned int _epoch = 0;    
    unsigned int _exposureCount = 0;
    unsigned int _gain = 0;
    unsigned int _bin = 0;
    unsigned int _readout = 0;
    double _exposureTime = 0;
    double _rightAscension = 0;
    double _declination = 0;
    double _delayTime = 0;
};

#endif // ATCCSPLAN_H
