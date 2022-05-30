#pragma once

#include <thread>
#include <vector>
#include <atomic>
#include <functional>

class ThreadPool
{
public:

    ThreadPool();
    ~ThreadPool();
    
    bool isActive() const { return m_active; }

    void createThreads(std::function<void()> func, const int numOfThreads);

    void shutdown();

private:

    void destroyThreads();

    std::vector<std::thread>    m_threads;
    std::atomic_bool            m_active { false };
};
