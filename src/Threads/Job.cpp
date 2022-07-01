#include "Threads/Job.hpp"

Job::Job(std::function<void()> func) :
        func(func)
{ /* NOTHING */ }        

void Job::execute() {
    State expected = State::AVAILABLE;
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
        hasExecuted.wait(State::FINISHED);

        if(hasExecuted == State::FINISHED) return;
    }
}