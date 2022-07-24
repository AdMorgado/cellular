#include <gtest/gtest.h>

#include "Threads/ThreadPool.hpp"

TEST(ThreadPoolTest, Construction) {
    EXPECT_NO_THROW({
        ThreadPool pool(1);
        pool.shutdown();
    });
}

TEST(ThreadPoolTest, ValidUse) {
    EXPECT_NO_THROW({
        ThreadPool pool(1);
        pool.shutdown();
    });
}

TEST(ThreadPoolTest, InvalidUse) {
    EXPECT_THROW({
        ThreadPool pool(1);
        pool.shutdown();
        Job job([]{});
        pool.execute(&job);
    }, std::runtime_error);
}
