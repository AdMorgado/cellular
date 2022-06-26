#pragma once

#include <atomic>
#include <functional>

class Job
{
public: 
    Job(std::function<void()> func) :
        func(func)
    { /* NOTHING */ }        

    void execute() {
        func();
        hasExecuted = true;
        hasExecuted.notify_all();
    }

    void join() {
        if(hasExecuted) return;
        while(true) {
            hasExecuted.wait(false);

            if(hasExecuted) return;
        }
    }

private:
    std::function<void()>   func;
    std::atomic_bool        hasExecuted { false };
};

