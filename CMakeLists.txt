cmake_minimum_required(VERSION 3.10)

project(project)
set(CMAKE_CXX_STANDARD 14) # JetsonGPIO seems not to work with C++11

include_directories(
    inc
)

file(GLOB_RECURSE SOURCES
    "inc/*.*"
    "src/*.*"
)

find_package(JetsonGPIO)

add_executable(test_spi ${SOURCES})
target_link_libraries(test_spi JetsonGPIO::JetsonGPIO)
