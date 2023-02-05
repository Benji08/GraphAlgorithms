cmake_minimum_required(VERSION 3.21)
project(22l-aisd-grafy-pawlak-ziarek)

set(CMAKE_CXX_STANDARD 14)

include_directories(.
        Boards
        DijkstraAlgorithm
        Graph
        GraphUnitTest)

add_executable(22l-aisd-grafy-pawlak-ziarek
        Dijkstra.cpp
        DijkstraAlgorithm/DijkstraAlgorithm.h
        DijkstraAlgorithm/DijkstarAlgorithm.cpp
        Graph/Graph.h
        Graph/Graph.cpp
        )

#Testy
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
if (WIN32)
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif (WIN32)#ifndef _WIN32
#endif
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

enable_testing()
add_executable(GraphUnitTest
        GraphUnitTest/GraphUnitTest.cpp)

target_link_libraries(GraphUnitTest PUBLIC DijkstraAlgorithm gtest_main)
gtest_discover_tests(GraphUnitTest)
