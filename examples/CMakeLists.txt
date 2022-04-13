


add_executable(nothing EmptyLayer.cpp)
target_include_directories(nothing PUBLIC "${PROJECT_SOURCE_DIR}/src")
target_link_libraries(nothing PUBLIC cellular)

