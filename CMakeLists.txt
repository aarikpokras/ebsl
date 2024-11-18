cmake_minimum_required(VERSION 3.12)
project(ebsl)

list(INSERT SRCF 0 src/main.cpp src/aml.cpp src/fa.cpp)
set(HDRS src/include)

include_directories(${HDRS})
add_executable(ebsl ${SRCF})
