#include <Threads/ThreadPool.hpp>

#include <vector>
#include <thread>
#include <atomic>
#include <iostream>

#include "Threads/Job.hpp"


ThreadPool::ThreadPool()
{
    
}

ThreadPool::~ThreadPool()
{
    destroyThreads();
}

void ThreadPool::createThreads(std::function<void()> func, const int numOfThreads)
{
    m_active = true;
    for(int i = 0; i < numOfThreads; i++)
    {
        auto threadFunc = [&isActive = m_active, func](){
            while(isActive)
            {
                func();
            }
        };
        std::thread thr(threadFunc);
        m_threads.push_back(std::move(thr));
    }
}


void ThreadPool::shutdown()
{
    destroyThreads();
}

void ThreadPool::destroyThreads()
{
    m_active = false;

    //TODO: possibly check if threads are taking too long to shutdown
    for(std::thread& thr : m_threads)
        thr.join();

    m_threads.clear();
}


