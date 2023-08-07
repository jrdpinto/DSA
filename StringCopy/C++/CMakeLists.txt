# ReverseString C++

project(StringCopy LANGUAGES CXX)

# Collect all source files
file(GLOB_RECURSE sources *.cpp *.c *.h)

# Add executable and link source files
add_executable(StringCopy ${sources})
#target_compile_options(my_c_app PRIVATE -Wall -Wextra)
