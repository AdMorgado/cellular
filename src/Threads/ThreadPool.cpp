#include <Threads/ThreadPool.hpp>

#include <vector>
#include <thread>
#include <atomic>
#include <iostream>
#include <algorithm>

#include "Threads/Job.hpp"

#define THREADPOOL_EXC_SHUTDOWN "Thread Pool has already shutdown!"

using namespace std::chrono_literals;
constexpr auto THREAD_LIFETIME = 10ms;


void log(const std::string& msg) {
    std::cout << "[" << std::this_thread::get_id() << "] " << msg << std::endl;
}

ThreadPool::ThreadPool(uint32_t maxNumOfThreads) :
    maxNumOfThreads(maxNumOfThreads) {
    
}

ThreadPool::~ThreadPool() {
    shutdown();
}

/**
 * Must be called in possession of [m_mut]
 */
std::size_t ThreadPool::getNumOfThreads() const {
    return m_threads.size();
}

/**
 * Must be called in possession of [m_mut]
 */
void ThreadPool::createThread() {
    auto threadFunc = [pool = this, &isActive = m_active, &jobQueue = m_jobQueue](std::stop_token stoken) {
        log("Thread awaking");
        while(isActive) {
            Job* job = jobQueue.dequeue(THREAD_LIFETIME);
            if(job) {
                try {
                    job->execute();
                } 
                catch(const std::exception& exc) {
                    log("A job has thrown an exception.");
                } 
            }
            if(stoken.stop_requested()) {
                log("Thread has been request to stop");
                break;
            } 
        }
        log("Thread is stopping");
        pool->unregister(std::this_thread::get_id());
    };
    
    m_threads.push_back(std::jthread(threadFunc));
}

void ThreadPool::unregister(std::thread::id id) {
    std::lock_guard<std::mutex> guard(m_mut);

    std::remove_if(m_threads.begin(), m_threads.end(), [id = id](std::jthread& thr)
        { return id == thr.get_id(); }
    );
}


void ThreadPool::execute(Job* job)  {
    if(!m_active) throw std::runtime_error(THREADPOOL_EXC_SHUTDOWN);

    m_jobQueue.enqueue(job);

    std::lock_guard<std::mutex> guard(m_mut);
    if(m_jobQueue.getSize() > 0 && getNumOfThreads() < maxNumOfThreads) {
        createThread();
    }
}

void ThreadPool::shutdown() {
    m_active = false;

    std::lock_guard<std::mutex> guard(m_mut);
    m_threads.clear();
}