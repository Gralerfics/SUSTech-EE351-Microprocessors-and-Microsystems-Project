cmake_minimum_required(VERSION 3.10)

project(project)
set(CMAKE_CXX_STANDARD 14)

include_directories(
    inc
)

file(GLOB_RECURSE SOURCES
    "inc/*.*"
    "src/*.*"
)

find_library(WIRINGPI_LIBRARY NAMES wiringPi)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${WIRINGPI_LIBRARY})
