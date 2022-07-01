#pragma once

#include <atomic>
#include <exception>
#include <functional>

class Job
{
public: 
    Job(std::function<void()> func) :
        func(func)
    { /* NOTHING */ }        

    void execute() {
        State expected = State::AVAILABLE;
        if(hasExecuted.compare_exchange_strong(expected, State::EXECUTING)) {
            func();
            hasExecuted = State::FINISHED;
            hasExecuted.notify_all();
        } else {
            throw std::runtime_error("This job has already been handled");
        }
    }

    void join() {
        if(hasExecuted == State::FINISHED) return;
        
        while(true) {
            hasExecuted.wait(State::FINISHED);

            if(hasExecuted == State::FINISHED) return;
        }
    }

private:
    enum State : uint8_t {
        AVAILABLE, EXECUTING, FINISHED
    };

    std::function<void()>   func;
    std::atomic<State>      hasExecuted { State::AVAILABLE };
};

