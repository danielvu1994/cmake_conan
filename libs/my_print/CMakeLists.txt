cmake_minimum_required(VERSION 3.0.0)

project(MyPrintLib VERSION 1.0.0)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

#include_directories(${SampleProject_SOURCE_DIR}/my_print/inc)

#FILE(GLOB MySources "src/*.cpp")

#add_library(my_math SHARED ${MySources})

#target_include_directories(my_math PUBLIC include)
#target_link_libraries(my_math PUBLIC my_print ${CONAN_LIBS})

FILE(GLOB MySources "src/*.cpp")
add_library(my_print SHARED ${MySources})

#target_include_directories(my_print PUBLIC include)
target_include_directories(my_print PUBLIC 
$<INSTALL_INTERFACE:include>
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

target_link_libraries(my_print PUBLIC ${CONAN_LIBS})

FILE(GLOB MyHeaders "include/my_print/*.h")
install(TARGETS my_print EXPORT my_print_export LIBRARY DESTINATION lib/my_print)
install(EXPORT my_print_export FILE my_print-config.cmake DESTINATION lib/my_print)
install(FILES ${MyHeaders} DESTINATION include/my_print)
