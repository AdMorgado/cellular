#pragma once

#include <atomic>
#include <exception>
#include <functional>

class Job
{
public: 
    Job(std::function<void()> func);

    void execute();
    
    void join();

private:
    enum State : uint8_t {
        NEW, EXECUTING, FINISHED
    };

    std::function<void()>   func;
    std::atomic<State>      hasExecuted { State::NEW };
};

