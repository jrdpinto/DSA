# Hash Table C++

project(HashTable LANGUAGES CXX)

# Collect all source files
file(GLOB_RECURSE sources *.cpp *.c *.h)

# Add executable and link source files
add_executable(HashTable ${sources})
#target_compile_options(my_c_app PRIVATE -Wall -Wextra)
