cmake_minimum_required(VERSION 3.8)

set(TEST_NAME cellular_tests)

file(GLOB SOURCES 
    "Threads/*.cpp"
    "Utils/*.cpp"
    )

add_executable(${TEST_NAME} ${SOURCES})
target_link_libraries(${TEST_NAME} PUBLIC
    gtest
    gtest_main
    cellular
)

add_test(
    NAME ${TEST_NAME} 
    COMMAND ${TEST_NAME}
    )
