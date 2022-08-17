# Cellula
## Multi-Threaded Cellular Automata Game Engine

* Multi-threaded job system
* Written in C++20 
* Unit testing

### Building 

Use ```cmake``` to build the project.
Additionally options are presented, ```BUILD_EXAMPLES``` and ```BUILD_TESTS``` to build game examples and unit tests respectively.
```
cmake -DBUILD_EXAMPLES=ON -DBUILD_TESTS=ON .
```


### Integrating

Currently, Cellular must be built in your project via CMake.
An easy implementation is adding the directory of the engine to your CMakeLists.txt and linking the library.
```
target_link_libraries(${PROJECT_NAME} PUBLIC cellular)
add_subdirectory(cellular)
```

