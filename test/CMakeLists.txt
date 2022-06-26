cmake_minimum_required(VERSION 3.8)

set(TEST_NAME cellular_tests)

file(GLOB SOURCES 
    "Threads/*.cpp"
    )

add_executable(${TEST_NAME} ${SOURCES})
target_include_directories(${TEST_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/src")
target_link_libraries(${TEST_NAME} PUBLIC
    gtest
    gtest_main
    cellular
)

add_test(
    NAME ${TEST_NAME} 
    COMMAND ${TEST_NAME}
    )
