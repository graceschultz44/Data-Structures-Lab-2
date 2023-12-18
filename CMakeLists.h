cmake_minimum_required(VERSION 3.15)
project(Assignment3_brackets)

set(CMAKE_CXX_STANDARD 17)

file(COPY test_data/ DESTINATION test_data/)
   
# show compiler output and enable warnings
set(CMAKE_VERBOSE_MAKEFILE ON)
add_compile_options(-Wall -Wextra -pedantic)

# Create the executable for sorting
add_executable(check_brackets main.cpp check_brackets.cpp)
#add_executable(check_brackets_vector main_vector.cpp)

set(CMAKE_VERBOSE_MAKEFILE OFF)

# testing with the single_include versions of Catch2 V2 (in directory catch2)
include(CTest)
add_executable(tests_list test_DSList.cpp)
add_test(NAME TestList COMMAND tests_list)
add_executable(tests_stack test_DSStack_Array.cpp)
add_test(NAME TestStack COMMAND tests_stack)
