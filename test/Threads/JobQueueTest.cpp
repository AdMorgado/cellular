#include <gtest/gtest.h>

#include "Utils/Defines.hpp"
#include "Threads/JobQueue.hpp"

#include <thread>

using namespace std::chrono_literals;

TEST(JobQueueTest, ValidUse) {
    JobQueue sut;

    //empty queue
    ASSERT_EQ(sut.dequeue(0ms), nullptr);

    Job job([]{});
    sut.enqueue(&job);
    ASSERT_EQ(sut.dequeue(0ms), &job);
}

TEST(JobQueueTest, SizeTest) {
    JobQueue sut;
    const int numOfJobs = 10;
    LOOP(i, numOfJobs) sut.enqueue(nullptr);
    ASSERT_EQ(sut.getSize(), numOfJobs);
}

TEST(JobQueueTest, EnqueueTest) {
    JobQueue sut;

    const int numOfJobs = 10;
    std::vector<Job*> jobs;
    LOOP(i, numOfJobs) jobs.push_back(new Job([]{})); // allocating because of job's no copyable semantics
    
    LOOP(i, numOfJobs) sut.enqueue(jobs[i]);
    LOOP(i, numOfJobs) ASSERT_EQ(sut.dequeue(0ms), jobs[i]);
    
    LOOP(i, numOfJobs) delete jobs[i];
}

TEST(JobQueueTest, DequeueTest) {
    JobQueue sut;

    Job job([]{});
    std::jthread thr([&]{
        ASSERT_EQ(sut.dequeue(100ms), &job);
    });

    sut.enqueue(&job);
}