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

    std::size_t getNumOfThreads() const;

    void destroyThreads();
    void createThread();

    void unregister(std::thread::id id);

    JobQueue                    m_jobQueue;
    std::mutex                  m_mut;
    std::vector<std::jthread>   m_threads;
    std::atomic_uint32_t const  maxNumOfThreads; //investigate if maxNumOfThreads needs to be atomic, as it is immutable
    std::atomic_bool            m_active { false };
};
