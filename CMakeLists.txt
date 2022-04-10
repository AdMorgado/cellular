cmake_minimum_required(VERSION 3.7)
project(cellular VERSION 0.0.1)

add_compile_options(-std=c++20)

find_package(SFML REQUIRED COMPONENTS graphics system window)

set(CMAKE_CXX_FLAGS "-Wall -pthread")

set(SFML sfml-system sfml-window sfml-graphics)

file(GLOB SOURCES 
    "src/Core/*.cpp"
    "src/Scene/*.cpp"
    "src/Utils/*.cpp"
    "src/Threads/*.cpp"
    "src/*.cpp" )

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE "src")
target_link_libraries(${PROJECT_NAME} ${SFML})