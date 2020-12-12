//
// Created by User on 14.11.2020.
//
#include <iostream>
#include "hash_map.hpp"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../catch.hpp"
#include <vector>

using namespace std;

TEST_CASE("LAB2") {
  SECTION("") {
    fefu::allocator<int> alloc;
    int *place = alloc.allocate();
    *place = 15;
    REQUIRE(*place == 15);
  }
  SECTION("") {
    fefu::allocator<int> alloc;
    int *data = alloc.allocate(50);
    alloc.deallocate(data, 50);
  }
  SECTION("") {
    fefu::hash_map<int, int>
        table({{21, 1},
               {0, 23},
               {2, 3},
               {-1, 11},
               {-12, 11},
               {21, 1}});
    fefu::hash_map<int, int> other_table(table.get_allocator());
    table.insert(std::make_pair(7, 1));
    table.insert(std::make_pair(2, 2));
    table.insert(std::make_pair(3, 3));
  }

  SECTION("") {
    fefu::hash_map<std::string, int> table(7);
    REQUIRE(table.bucket_count() == 7);
    REQUIRE(table.size() == 0);
    REQUIRE(table.empty());
  }
  SECTION("") {
    fefu::hash_map<std::string, int> table;
    REQUIRE(table.bucket_count() == 0);
    REQUIRE(table.size() == 0);
    REQUIRE(table.empty());
    REQUIRE(table.load_factor() == 0);
  }
  SECTION("") {
    fefu::hash_map<std::string, int> table(2);
    std::pair<std::string, int> element{"yes", 1};
    table.insert(element);
    REQUIRE(table.begin()->first == "yes");
    REQUIRE(table.begin()->second == 1);
  }
  SECTION("") {
    std::vector<std::pair<std::string, int>> elements(9);
    elements[0] = {"death", 1};
    elements[1] = {"rest", 2};
    elements[2] = {"in", 3};
    elements[3] = {"peace", 4};
    elements[4] = {"help", 5};
    // fefu::hash_map<std::string, int> table(elements.begin(), elements.end());
    // std::cout << table.contains("death");
  }
  SECTION("") {
    // fefu::hash_map<std::string, int> table
    //     ({{"death", 1}, {"rest", 23}, {"help", 3}, {"my", 11}, {"give", 11}});
    // REQUIRE(table.cbegin() == table.cend());
  }
  SECTION("") {
    fefu::hash_map<int, int> table(10);
    // table[6] = -120;
    // table[2] = 12;
    // REQUIRE(table[6] == -120);
    // REQUIRE(table[2] == 12);
  }
}

