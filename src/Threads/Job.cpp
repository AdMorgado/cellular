#include "Threads/Job.hpp"

#include <iostream>

Job::Job(std::function<void()> func) :
        func(func)
{ /* NOTHING */ }        

bool Job::execute() {
    State expected = State::NEW;
    if(hasExecuted.compare_exchange_strong(expected, State::EXECUTING)) {
        func();
        hasExecuted = State::FINISHED;
        hasExecuted.notify_all();
        return true;
    }

    return false;
}

void Job::join() {

    if(execute()) return;

    if(hasExecuted == State::FINISHED) return;
    while(true) {
        // TODO: wait isnt set on an old value, but rather a desired value, this might be problematic
        hasExecuted.wait(State::EXECUTING); 

        if(hasExecuted == State::FINISHED) return;
    }
}