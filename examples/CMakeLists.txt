
set(CMAKE_CXX_STANDARD_REQUIRED 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_FLAGS "-std=c++20 -Wall -pthread")

find_package(SFML REQUIRED COMPONENTS graphics system window)

set(SFML sfml-system sfml-window sfml-graphics)
set(EXAMPLE_NAME langtonsAnt)

add_executable(${EXAMPLE_NAME} LangtonsAnt.cpp)
target_link_libraries(${EXAMPLE_NAME} PUBLIC ${PROJECT_NAME})

