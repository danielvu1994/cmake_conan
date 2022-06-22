add_library(my_math
src/division.cpp
src/addition.cpp)

target_include_directories(my_math PUBLIC include)
