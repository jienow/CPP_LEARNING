
cmake_minimum_required(VERSION 3.15)
project(test)

add_definitions(-DFMT_HEADER_ONLY)
add_executable(main test.cpp)
find_package(fmt CONFIG REQUIRED)
target_link_libraries(main PRIVATE fmt::fmt)