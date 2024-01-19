# Graphs C++

project(Graphs LANGUAGES CXX)

# Collect all source files
file(GLOB_RECURSE sources *.cpp *.c *.h)

# Add executable and link source files
add_executable(Graphs ${sources})
#target_compile_options(my_c_app PRIVATE -Wall -Wextra)
