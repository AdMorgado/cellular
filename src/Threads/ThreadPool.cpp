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

void awaitForJobs()
{
    while(true)
    {
        Job* job = nullptr;
        if(job)
        {
            
        } else {
            std::this_thread::yield();
        }
    }
}

void ThreadPool::createThreads(const int numOfThreads)
{
    m_active = true;
    for(int i = 0; i < numOfThreads; i++)
    {
        std::thread thr(awaitForJobs);
        m_threads.push_back(std::move(thr));
    }
}


void ThreadPool::stopThreads()
{
    m_active = false;
    // TODO: empty thread pool
    for(std::thread& thr : m_threads)
        thr.join();

    m_threads.clear();
}

void ThreadPool::synchronize()
{



}

