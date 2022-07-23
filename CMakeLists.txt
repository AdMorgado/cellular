cmake_minimum_required(VERSION 3.8)
project(cellular VERSION 0.0.1)

find_package(OpenGL REQUIRED COMPONENTS OpenGL)
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

file(GLOB IMGUI_SOURCES
    "vendor/imgui/imgui.cpp"
    "vendor/imgui/imgui_draw.cpp"
    "vendor/imgui/imgui_tables.cpp"
    "vendor/imgui/imgui_widgets.cpp"
    "vendor/imgui-sfml/imgui-SFML.cpp"
) 

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${IMGUI_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC 
    "src" 
    "vendor/entt/include"
    "vendor/imgui"
    "vendor/imgui-sfml"
)

target_link_libraries(${PROJECT_NAME} 
    ${SFML}
    ${OPENGL_LIBRARIES}
)


enable_testing()

add_subdirectory(test)
add_subdirectory(examples)
