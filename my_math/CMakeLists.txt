FILE(GLOB MySources "src/*.cpp")

add_library(my_math SHARED ${MySources})

target_include_directories(my_math PUBLIC include)
target_link_libraries(my_math PUBLIC my_print ${CONAN_LIBS})
