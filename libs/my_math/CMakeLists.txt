cmake_minimum_required(VERSION 3.0.0)

project(MyMathLib VERSION 1.0.0)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

#include_directories(${SampleProject_SOURCE_DIR}/my_print/inc)
find_package(my_print)

if(my_print_FOUND)
else()
	message(FATAL_ERROR "my_print lib is not found")
	EXIT()
endif()

FILE(GLOB MySources "src/*.cpp")

add_library(my_math SHARED ${MySources})

#target_include_directories(my_math PUBLIC include)
target_include_directories(my_math PUBLIC
$<INSTALL_INTERFACE:include>
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

target_link_libraries(my_math LINK_PUBLIC  my_print ${CONAN_LIBS})

FILE(GLOB MyHeaders "include/my_math/*.h")
install(TARGETS my_math EXPORT my_math_export LIBRARY DESTINATION lib/my_math)
install(EXPORT my_math_export FILE my_math-config.cmake DESTINATION lib/my_math)
install(FILES ${MyHeaders} DESTINATION include/my_math)
