#pragma once

#include <mutex>
#include <queue>
#include <vector>
#include <chrono>
#include <condition_variable>

#include "Threads/Job.hpp"

/**
 * @brief This instance is thread-safe.
 * 
 */
class JobQueue 
{
public:

    void enqueue(Job* job);
    Job* dequeue(std::chrono::milliseconds timeout);
    
private:   

    std::mutex              m_mut;
    std::condition_variable m_cond;
    std::queue<Job*>        m_queue;
};


