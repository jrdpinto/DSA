# Balanced parentheses C++

project(BalancedParentheses LANGUAGES CXX)

# Collect all source files
file(GLOB_RECURSE sources *.cpp *.c *.h)

# Add executable and link source files
add_executable(BalancedParentheses ${sources})
