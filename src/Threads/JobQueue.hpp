#pragma once

#include <mutex>
#include <queue>
#include <vector>
#include <chrono>
#include <condition_variable>

#include "Threads/Job.hpp"

/**
 * @brief This instance is thread-safe. Jobs are queued and dequeued by consuming threads
 * Consuming threads will also respect a FIFO order
 * 
 */
class JobQueue 
{
public:

    void enqueue(Job* job);
    Job* dequeue(std::chrono::milliseconds timeout);

    std::size_t getSize();

private:   

    struct Request {
        Request(std::condition_variable& cond) :
            cond(cond) 
        { }
        std::condition_variable&    cond;
        Job*                        job { nullptr };
    };

    std::mutex              m_mut;
    std::queue<Job*>        m_queue;
    std::queue<Request*>    m_requests;
};


