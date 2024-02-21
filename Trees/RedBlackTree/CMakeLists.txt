# Binary Tree C++

project(BinaryTree LANGUAGES CXX)

# Collect all source files
file(GLOB_RECURSE sources *.cpp *.c *.h)

# Add executable and link source files
add_executable(BinaryTree ${sources})