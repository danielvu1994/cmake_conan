cmake_minimum_required(VERSION 3.0.0)

project(SampleApp VERSION 1.0.0)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake) 
conan_basic_setup()

find_package(my_math REQUIRED)
find_package(my_print)

if(my_math_FOUND)
else()
	message(FATAL_ERROR "my_math is not found")
	EXIT()
endif()
#include_directories(${SampleProject_SOURCE_DIR}/my_math/inc)

FILE(GLOB MySources "src/*.cpp")
add_executable(calculator
${MySources})

#target_include_directories(calculator PUBLIC ${my_math_INCLUDE_DIRS})
target_link_libraries(calculator PUBLIC my_math)
message("my math libs: "${my_math_LIBRARIES})
message("my_math_include: " ${my_math_INCLUDE_DIRS})
