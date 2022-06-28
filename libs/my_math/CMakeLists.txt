cmake_minimum_required(VERSION 3.0.0)

project(MyMathLib VERSION 1.0.0)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

#include_directories(${SampleProject_SOURCE_DIR}/my_print/inc)
find_package(my_print REQUIRED PATHS /home/daniel/cmake_conan/build_dir)
set(CMAKE_INSTALL_RPATH $ENV{INSTALL_PATH})
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

if(my_print_FOUND)
	message("Found my_print lib")
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

set(CMAKE_INSTALL_PREFIX $ENV{INSTALL_PATH})
FILE(GLOB MyHeaders "include/my_math/*.h")
install(TARGETS my_math EXPORT my_math_export LIBRARY DESTINATION lib/my_math)
install(EXPORT my_math_export FILE my_math-config.cmake DESTINATION lib/my_math)
install(FILES ${MyHeaders} DESTINATION include/my_math)
