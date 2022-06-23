cmake_minimum_required(VERSION 3.0.0)
project(mosquitto_test)

add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(mos main.cpp)
target_link_libraries(mos ${CONAN_LIBS})
