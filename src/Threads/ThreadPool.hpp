#pragma once

#include <thread>
#include <vector>
#include <atomic>
#include <functional>

#include "Threads/JobQueue.hpp"

class ThreadPool
{
public:

    ThreadPool();
    ~ThreadPool();

    void createThreads(int numOfThreads);

    void shutdown();

    void execute(Job* job);

private:

    void destroyThreads();

    JobQueue                    m_jobQueue;

    std::vector<std::jthread>   m_threads;
    std::atomic_bool            m_active { false };
};
