#include "Threads/Job.hpp"

#include <iostream>

Job::Job(std::function<void()> func) :
        func(func)
{ /* NOTHING */ }        

void Job::execute() {
    State expected = State::NEW;
    if(hasExecuted.compare_exchange_strong(expected, State::EXECUTING)) {
        func();
        hasExecuted = State::FINISHED;
        hasExecuted.notify_all();
    } else {
        throw std::runtime_error("This job has already been handled");
    }
}

void Job::join() {
    if(hasExecuted == State::FINISHED) return;
    while(true) {
        // TODO: wait isnt set on an old value, but rather a desired value, this might be problematic
        hasExecuted.wait(State::EXECUTING); 

        if(hasExecuted == State::FINISHED) return;
    }
}