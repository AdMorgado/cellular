#include "Threads/JobQueue.hpp"


void JobQueue::enqueue(Job* job) {
    std::unique_lock<std::mutex> lock(m_mut);
    if(!m_requests.empty()) {
        Request* req = m_requests.front();
        req->cond.notify_one();
        req->job = job;
        m_requests.pop();
    } else {
        m_queue.push(job);
    }
}

Job* JobQueue::dequeue(std::chrono::milliseconds timeout) {
    std::unique_lock<std::mutex> lock(m_mut);

    if(!m_queue.empty()) {
        Job* job = m_queue.front();
        m_queue.pop();
        return job;
    }

    std::condition_variable cond;
    Request req(cond);
    m_requests.push(&req);

    while(true) 
    {  
        std::cv_status status = cond.wait_for(lock, timeout);
        if(req.job) return req.job;
        if(status == std::cv_status::timeout) return nullptr;
    }
}

std::size_t JobQueue::getSize() {
    std::lock_guard<std::mutex> lock(m_mut);
    return m_queue.size();
}