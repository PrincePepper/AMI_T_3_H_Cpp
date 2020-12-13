//
// Created by User on 14.12.2020.
//
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

template<class A, class B>
struct Convert;

#include "is_customly_convertible.h"

struct Test {
  int a, b;
};

template<>
struct Convert<int, int> {
  int operator()(const int &a) {
    return a;
  }
};

template<>
struct Convert<int, float> {
  float operator()(const int &a) {
    return a;
  }
};

template<>
struct Convert<Test, int> {
  int operator()(const Test &a) {
    return a.a + a.b;
  }
};

int main() {
  static_assert(!std::is_trivially_constructible<NoTriviallyConstructible>::value);

  static_assert(!std::is_copy_constructible<NoCopyConstructible>::value);
  static_assert(!std::is_copy_assignable<NoCopyConstructible>::value);


  static_assert(is_customly_convertible<int, int>::value);

  static_assert(is_customly_convertible<int, float>::value);
  static_assert(!is_customly_convertible<float, float>::value);

  static_assert(is_customly_convertible<Test, int>::value);
  static_assert(!is_customly_convertible<int, Test>::value);

  static_assert(is_customly_convertible<NoCopyConstructible,
                                        NoTriviallyConstructible>::value);
  static_assert(!is_customly_convertible<NoTriviallyConstructible,
                                         NoCopyConstructible>::value);

  static_assert(!is_customly_convertible<NoCopyConstructible, int>::value);
  static_assert(!is_customly_convertible<int, NoCopyConstructible>::value);

  std::cout << 1;
}
