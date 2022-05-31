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
        hasExecuted = true;
    }

    void join() 
    {
        //TODO: switch this while with an await on the atomic variable
        while(!hasExecuted);
    }

private:
    std::function<void()>   func;
    std::atomic_bool        hasExecuted { false };
};

