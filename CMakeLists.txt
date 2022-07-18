cmake_minimum_required(VERSION 3.7)
project(cellular VERSION 0.0.1)

find_package(SFML REQUIRED COMPONENTS graphics system window)

set(CMAKE_CXX_STANDARD_REQUIRED 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_FLAGS "-std=c++20 -Wall -pthread")

set(SFML sfml-system sfml-window sfml-graphics)

file(GLOB SOURCES 
    "src/Core/*.cpp"
    "src/Scene/*.cpp"
    "src/Utils/*.cpp"
    "src/Threads/*.cpp"
    "src/*.cpp" 
)



add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC 
    "src" 
    "vendor/entt/include"
)

target_link_libraries(${PROJECT_NAME} ${SFML})

enable_testing()

add_subdirectory(test)
add_subdirectory(examples)
