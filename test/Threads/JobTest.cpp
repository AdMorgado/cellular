
#include <gtest/gtest.h>

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