//
// Created by Semen Sereda on 14.12.2020.
//

#pragma once

struct NoCopyConstructible {
  NoCopyConstructible(const NoCopyConstructible &copy) = delete;

  NoCopyConstructible operator=(const NoCopyConstructible &copy) = delete;
};

struct NoTriviallyConstructible {
  NoTriviallyConstructible() = delete;
};

Test t;

template<>
struct Convert<NoTriviallyConstructible, int> {
  int operator()(const int &temp) {
    return temp;
  }
};

template<>
struct Convert<NoCopyConstructible, NoTriviallyConstructible> {
  int operator()(const int &temp) {
    return temp;
  }
};

template<class S, class F>
static constexpr decltype(std::declval<Convert<S, F>>().operator()(t),
    bool()) test(int a) {
  return true;
}

template<class S, class F>
static constexpr decltype(std::declval<Convert<S, F>>().operator()(0),
    bool()) test(int a) {
  return true;
}

template<class S, class F>
static constexpr bool test(...) {
  return false;
}

template<class T, class P>
struct is_customly_convertible {
  static constexpr bool value = test<T, P>(0);
};
