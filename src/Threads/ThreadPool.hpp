#pragma once

#include <thread>
#include <vector>
#include <functional>

class ThreadPool
{
public:

    ThreadPool();
    ~ThreadPool();
    
    bool isActive() const { return m_active; }

    void createThreads(const int numOfThreads);
    void stopThreads();

    void synchronize();

private:

    std::vector<std::thread>    m_threads;
    std::function<void()>       m_func;

    bool                        m_active { false };

};
