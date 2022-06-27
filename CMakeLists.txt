cmake_minimum_required(VERSION 3.0.0)

project(SampleProject VERSION 1.0.0)

add_subdirectory(app/sample)

add_subdirectory(lib/my_print)
add_subdirectory(lib/my_math)
#FILE(GLOB MySources "src/*.cpp")
#add_executable(calculator
#${MySources})

#target_link_libraries(calculator PUBLIC my_math)
