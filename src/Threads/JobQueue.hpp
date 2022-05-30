#pragma once

#include <mutex>
#include <queue>
#include <vector>
#include <chrono>
#include <condition_variable>

#include "Threads/Job.hpp"

class JobQueue 
{
public:

    void enqueue(Job* job)
    {
        std::unique_lock<std::mutex> lock(m_mut);
        m_queue.push(job);
        m_cond.notify_one();
    }

    Job* dequeue(std::chrono::nanoseconds timeout)
    {
        std::unique_lock<std::mutex> lock(m_mut);

        if(!m_queue.empty()) {
            Job* job = m_queue.front();
            m_queue.pop();
            return job;
        }

        while(true) 
        {  
            auto status = m_cond.wait_for(lock, timeout);

            if(!m_queue.empty()) {
                Job* job = m_queue.front();
                m_queue.pop();
                return job;
            }
        }
    }
    
private:   

    std::mutex              m_mut;
    std::condition_variable m_cond;
    std::queue<Job*>        m_queue;
};


