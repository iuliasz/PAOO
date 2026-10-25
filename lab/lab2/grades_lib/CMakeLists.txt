cmake_minimum_required(VERSION 3.18)
project(grades_lib CXX)

add_library(grades STATIC src/grades.cpp)
target_include_directories(grades PUBLIC include)

install(TARGETS grades ARCHIVE DESTINATION lib)
install(FILES include/grades.h DESTINATION include)