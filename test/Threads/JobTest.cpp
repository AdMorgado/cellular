
#include <gtest/gtest.h>

#include "Cellular.hpp"

TEST(JobTest, ValidUse)
{
    Job job([](){});
    job.execute();
    job.join();
}
