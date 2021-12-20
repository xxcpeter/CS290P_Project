CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

project(softHeap)
set(EXECUTABLE_OUTPUT_PATH
        ${PROJECT_SOURCE_DIR}/bin)

add_library(softHeap
        STATIC
        src/softHeap.cpp)
target_include_directories(softHeap
        PUBLIC
        include)

add_executable(softHeapTest
        test/main.cpp)
target_link_libraries(softHeapTest
        PRIVATE
        softHeap)