#include "Threads/JobQueue.hpp"

#include <iostream>

void JobQueue::enqueue(Job* job) {
    std::unique_lock<std::mutex> lock(m_mut);
    if(!m_requests.empty()) {
        Request* req = m_requests.front();
        m_requests.pop_front();
        req->job = job;
        req->cond.notify_one();
    } else {
        m_queue.push(job);
    }
}

Job* JobQueue::dequeue(std::chrono::milliseconds timeout) {
    std::unique_lock<std::mutex> lock(m_mut);

    if(m_requests.empty() && !m_queue.empty()) {
        Job* job = m_queue.front();
        m_queue.pop();
        return job;
    }

    std::condition_variable cond;
    Request req(cond);
    m_requests.push_back(&req);

    while(true) 
    {  
        std::cv_status status = cond.wait_for(lock, timeout);
        // by checking first priority is given to returning req.job over timeout
        if(req.job) return req.job;
        if(status == std::cv_status::timeout) {
            // removing request
            m_requests.erase(std::remove(m_requests.begin(), m_requests.end(), &req), m_requests.end());
            return nullptr;
        }
    }
}

std::size_t JobQueue::getSize() {
    std::lock_guard<std::mutex> lock(m_mut);
    return m_queue.size();
}