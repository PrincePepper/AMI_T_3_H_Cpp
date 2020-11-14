cmake_minimum_required(VERSION 3.17)
project(PMI_T_3_H_Cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(1_primeNumberGenerator "tournament 1/1_PrimeNumberGenerator/main.cpp" "tournament 1/1_PrimeNumberGenerator/prime_gen.h")
add_executable(2_FiniteField "tournament 1/2_Finite_Field(Easy_version)/num.cpp" "tournament 1/2_Finite_Field(Easy_version)/num.h" "tournament 1/2_Finite_Field(Easy_version)/main.cpp")
add_executable(3_Date "tournament 1/3_Date/date.h" "tournament 1/3_Date/main.cpp")
add_executable(4_Set "tournament 1/4_Set/main.cpp" "tournament 1/4_Set/set.h")
add_executable(5_FiniteField "tournament 1/5_Finite_Field(Hard_version)/num.h" "tournament 1/5_Finite_Field(Hard_version)/num.cpp" "tournament 1/5_Finite_Field(Hard_version)/main.cpp")
add_executable(6_BufferedReader "tournament 1/6_BufferedReader/main.cpp" "tournament 1/6_BufferedReader/buffered_reader.h")

add_executable(1_pinter "tournament 2/1_SmartPointer/SmartPointer.h" "tournament 2/1_SmartPointer/main.cpp" "tournament 2/1_SmartPointer/Test_SmartPointer.h" "tournament 2/1_SmartPointer/Test.h")
add_executable(2_factory "tournament 2/2_factory/factory.h" "tournament 2/2_factory/main.cpp")
add_executable(3_fixed "tournament 2/3_FixedAllocator/fixed_allocator.h" "tournament 2/3_FixedAllocator/fixed_allocator.cpp")
add_executable(4_code "tournament 2/4_Code_format_visitor/format_visitor.h" "tournament 2/4_Code_format_visitor/main.cpp")
add_executable(5_gamedatabase "tournament 2/5_GameDatabase/game_database.h" "tournament 2/5_GameDatabase/main.cpp")

add_executable(complex "LAB 1/Complex.h"  "LAB 1/Rational.h" "LAB 1/tests.cpp")
add_executable(hashmap "LAB 2/hash_map.cpp"  "LAB 2/hash_map.hpp" "LAB 2/tests.cpp")
# add coverage
# https://plugins.jetbrains.com/plugin/11031-c-c--coverage
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_compile_options(-fprofile-instr-generate -fcoverage-mapping)
    add_link_options(-fprofile-instr-generate)
    #Uncomment in case of linker errors
    #link_libraries(clang_rt.profile-x86_64)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options(--coverage)
    #Uncomment in case of linker errors
    #link_libraries(gcov)
endif ()