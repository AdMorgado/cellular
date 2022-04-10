cmake_minimum_required(VERSION 3.8)

set(NOME cellular_tests)

#file(GLOB SOURCES 
#    "*.cpp"
#    )

add_executable(${NOME} exampletest.cpp)
target_link_libraries(${NOME} PUBLIC
    gtest
    gtest_main
    cellular
)

add_test(
    NAME ${NOME} 
    COMMAND ${NOME}
    )
