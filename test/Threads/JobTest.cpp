
#include <gtest/gtest.h>

#include <thread>

#include "Cellular.hpp"

TEST(JobTest, ValidUse) {
    Job job([](){});
    ASSERT_NO_THROW(job.execute());
    job.join();
}

constexpr int NUM_OF_REPS = 100'000;

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
