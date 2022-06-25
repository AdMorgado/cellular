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

void ThreadPool::createThreads(int numOfThreads)
{
    m_active = true;
    for(int i = 0; i < numOfThreads; i++)
    {
        auto threadFunc = [&isActive = m_active, &jobQueue = m_jobQueue](std::stop_token stoken){
            while(isActive)
            {
                //Job* job = jobQueue; 
                if(stoken.stop_requested()) {
                    break;
                }
            }
        };
        std::jthread thr(threadFunc);
        m_threads.push_back(std::move(thr));
    }
}


void ThreadPool::shutdown()
{
    destroyThreads();
}

void ThreadPool::execute(Job* job)
{
    m_jobQueue.enqueue(job);
}

void ThreadPool::destroyThreads()
{
    m_active = false;

    //TODO: possibly check if threads are taking too long to shutdown
    for(std::jthread& thr : m_threads){
        thr.request_stop();
        thr.join();
    }

    m_threads.clear();
}


