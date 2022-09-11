#pragma once

#include <atomic>
#include <exception>
#include <functional>

class Job
{
public: 
    Job();
    Job(std::function<void()> func);

    bool execute();
    
    void join();

private:
    enum State : uint8_t {
        AVAILABLE, EXECUTING, FINISHED
    };

    std::function<void()>   func;
    std::atomic<State>      hasExecuted { State::AVAILABLE };
};

