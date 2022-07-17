
#include <gtest/gtest.h>

#include <thread>

#include "Cellular.hpp"

TEST(JobTest, ValidUse) {
    Job job([](){});
    ASSERT_NO_THROW(job.execute());
    job.join();
}

TEST(JobTest, InvalidUse) {
    Job job([](){});
    ASSERT_NO_THROW(job.execute());
    ASSERT_THROW(job.execute(), std::runtime_error);
}

constexpr int NUM_OF_REPS = 10000;

TEST(JobTest, ExhaustiveTest) {
    for(int i = 0; i < NUM_OF_REPS; i++) {
        Job job([](){});
        std::thread thr([&job = job](){
            job.execute();
        });
        job.join();
        thr.join();
    }
}
