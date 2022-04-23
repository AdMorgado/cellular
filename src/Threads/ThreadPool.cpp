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
    m_active = false;
    for(std::thread& thr : m_threads)
        thr.join();

    m_threads.clear();
}


