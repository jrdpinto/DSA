# ReverseString C++

project(ReverseString LANGUAGES CXX)

# Collect all source files
file(GLOB_RECURSE sources *.cpp *.c *.h)

# Add executable and link source files
add_executable(ReverseString ${sources})
#target_compile_options(my_c_app PRIVATE -Wall -Wextra)
