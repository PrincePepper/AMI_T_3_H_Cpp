cmake_minimum_required(VERSION 3.17)
project(PMI_T_3_H_Cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(1_primeNumberGenerator "tournament 1/1_PrimeNumberGenerator/main.cpp" "tournament 1/1_PrimeNumberGenerator/prime_gen.h")
add_executable(2_FiniteField "tournament 1/2_Finite_Field(Easy_version)/num.cpp" "tournament 1/2_Finite_Field(Easy_version)/num.h" "tournament 1/2_Finite_Field(Easy_version)/main.cpp")
add_executable(3_Date "tournament 1/3_Date/date.h" "tournament 1/3_Date/main.cpp")
add_executable(4_Set "tournament 1/4_Set/main.cpp" "tournament 1/4_Set/set.h")
add_executable(5_FiniteField "tournament 1/5_Finite_Field(Hard_version)/num.h" "tournament 1/5_Finite_Field(Hard_version)/num.cpp" "tournament 1/5_Finite_Field(Hard_version)/main.cpp")
add_executable(6_BufferedReader "tournament 1/6_BufferedReader/main.cpp" "tournament 1/6_BufferedReader/buffered_reader.h")

add_executable(complex "LAB 1/Complex.h"  "LAB 1/Rational.h" "LAB 1/tests.cpp")

# add coverage
# https://plugins.jetbrains.com/plugin/11031-c-c--coverage
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options(--coverage)
    link_libraries(gcov)
endif ()