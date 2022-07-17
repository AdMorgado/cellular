#include "Threads/JobQueue.hpp"


void JobQueue::enqueue(Job* job) {
    std::unique_lock<std::mutex> lock(m_mut);
    m_queue.push(job);
    m_cond.notify_one();
}

Job* JobQueue::dequeue(std::chrono::milliseconds timeout) {
    std::unique_lock<std::mutex> lock(m_mut);

    if(!m_queue.empty()) {
        Job* job = m_queue.front();
        m_queue.pop();
        return job;
    }

    while(true) 
    {  
        std::cv_status status = m_cond.wait_for(lock, timeout);

        switch(status) {
            case std::cv_status::no_timeout:
                if(!m_queue.empty()) {
                    Job* job = m_queue.front();
                    m_queue.pop();
                    return job;
                }
                break;
            case std::cv_status::timeout:
                return nullptr;
                break;
        }
    }
}

std::size_t JobQueue::getSize() {
    std::lock_guard<std::mutex> lock(m_mut);
    return m_queue.size();
}