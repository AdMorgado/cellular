#include <Threads/ThreadPool.hpp>

#include <vector>
#include <thread>
#include <atomic>
#include <iostream>

#include "Threads/Job.h"

std::vector<std::thread> threads;

std::atomic_bool runThreads = false;

void listenToJobs()
{
    runThreads = true;

    while(runThreads)
    {
        Job* job = nullptr;
        if(job)
        {

        }
        else 
        {
            std::this_thread::yield();
        }
    }
}

void startThreadPool(const int numOfThreads)
{
    for(int i = 0; i < numOfThreads; i++)
    {
        threads.push_back(std::thread(listenToJobs));
        
    }
}


void stopThreadPool()
{
    runThreads = false;
    for(std::thread& thr : threads)
    {
        thr.join();
    }
}

