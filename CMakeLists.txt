cmake_minimum_required(VERSION 3.17)
PROJECT(FileScrambler)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

FILE(GLOB SOURCES "hellpackgen.cpp" "Scrambler.cpp" "*.hpp" "*.h")
add_executable(HellpackGen ${SOURCES})
target_include_directories(HellpackGen PRIVATE "cxxopts/include/")
