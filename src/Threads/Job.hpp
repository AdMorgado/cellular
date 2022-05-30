#pragma once

#include <atomic>
#include <functional>

class Job
{
public:
    Job() = default;        
    Job(std::function<void()> func) :
        func(func)
    { /* NOTHING */ }        

    void execute()
    {
        func();
    }

private:

    std::function<void()> func;
};

