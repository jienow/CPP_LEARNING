cmake_minimum_required(VERSION 3.0)
project(new_cpp03)

set(CMAKE_CXX_STANDARD 20)

add_executable(new_cpp03 main.cpp)
find_package(fmt CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)
