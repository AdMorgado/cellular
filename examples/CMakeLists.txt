

set(CMAKE_CXX_STANDARD_REQUIRED 20)

add_executable(particles ParticlesLayer.cpp)
target_include_directories(particles PUBLIC "${PROJECT_SOURCE_DIR}/src")
target_link_libraries(particles PUBLIC cellular)

