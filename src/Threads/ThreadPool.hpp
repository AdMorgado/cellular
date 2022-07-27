#pragma once

#include <thread>
#include <vector>
#include <atomic>
#include <functional>

#include "Threads/JobQueue.hpp"

class ThreadPool
{
public:

    ThreadPool(uint32_t maxNumOfThreads);
    ~ThreadPool();

    void execute(Job* job);
    
    void shutdown();

private:

    enum State : uint8_t {
        AVAILABLE,
        SHUTDOWN
    };

    std::size_t getNumOfThreads() const;

    void createThread();

    void unregister(std::thread::id id);

    JobQueue                    m_jobQueue;
    std::mutex                  m_mut;
    std::vector<std::thread>    m_threads;
    const uint32_t              maxNumOfThreads; 
    std::atomic_bool            m_active { true };
};
