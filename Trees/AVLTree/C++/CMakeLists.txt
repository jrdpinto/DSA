# AVL Tree C++

project(AVLTree LANGUAGES CXX)

# Collect all source files
file(GLOB_RECURSE sources *.cpp *.c *.h)

# Add executable and link source files
add_executable(AVLTree ${sources})