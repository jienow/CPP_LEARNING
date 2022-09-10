cmake_minimum_required(VERSION 3.23)
project (learn14)

set(CMAKE_CXX_STANDARD 20)
aux_source_directory(src DIR_SRC)
include_directories(${PROJECT_NAME} include)
add_executable(learn14 ${DIR_SRC})
