cmake_minimum_required(VERSION 3.18)
project(grades_app CXX)

set(GRADES_DIR "${CMAKE_SOURCE_DIR}/../install")
find_library(GRADES_LIB grades PATHS "${GRADES_DIR}/lib" NO_DEFAULT_PATH REQUIRED)

add_executable(app main.cpp)
target_include_directories(app PRIVATE "${GRADES_DIR}/include")
target_link_libraries(app PRIVATE "${GRADES_LIB}")
