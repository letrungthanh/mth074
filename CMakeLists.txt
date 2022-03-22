cmake_minimum_required(VERSION 3.16)

project(mth074)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(mth074 mth074.cpp)
target_link_libraries(mth074 gmpxx gmp)