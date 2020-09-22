cmake_minimum_required(VERSION 3.17)
project(PMI_T_3_H_Cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(1_primeNumberGenerator "tournament 1/1_PrimeNumberGenerator/main.cpp" "tournament 1/1_PrimeNumberGenerator/prime_gen.h")
add_executable(2_FiniteField "tournament 1/2_Finite_Field(Easy_version)/Num.cpp" "tournament 1/2_Finite_Field(Easy_version)/Num.h" "tournament 1/2_Finite_Field(Easy_version)/main.cpp")
add_executable(3_Date "tournament 1/3_Date/date.cpp" "tournament 1/3_Date/date.h" "tournament 1/3_Date/main.cpp")