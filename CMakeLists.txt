cmake_minimum_required(VERSION 3.1)
project(sv.rest
        VERSION 1.0
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED)

find_package(fmt REQUIRED)

include_directories("${CMAKE_SOURCE_DIR}/include/")

# add_subdirectory(src)

# test make_bytes.hpp
add_executable(make_bytes "sv/common/make_bytes.hpp")