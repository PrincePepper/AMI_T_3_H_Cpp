#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include "Complex.h"
#include "Rational.h"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

TEST_CASE("Complex numbers") {

  SECTION("creating a class and writing and comparing with itself") {
    Complex<int> a_int(5, 2);
    Complex<int> b_int(3, -3);
    Complex<int> c_int(3, 0);

    Complex<double> a_d(5, 2);
    Complex<double> b_d(3, -3);
    Complex<double> c_d(3, 0);
    Complex<double> d_d(5.5, 2.5);
    Complex<double> e_d(3.5, -3.5);
    Complex<double> f_d(3.5, 0.5);
    Complex<double> g_d(3.5, 0);

    Complex<float> a_f(5, 2);
    Complex<float> b_f(3, -3);
    Complex<float> c_f(3, 0);
    Complex<float> d_f(5.5, 2.5);
    Complex<float> e_f(3.5, -3.5);
    Complex<float> f_f(3.5, 0.5);
    Complex<float> g_f(3.5, 0);

    a_int = a_int;
    b_int = b_int;
    c_int = c_int;
    a_d = a_d;
    b_d = b_d;
    c_d = c_d;
    d_d = d_d;
    e_d = e_d;
    f_d = f_d;
    g_d = g_d;
    a_f = a_f;
    b_f = b_f;
    c_f = c_f;
    d_f = d_f;
    e_f = e_f;
    f_f = f_f;
    g_f = g_f;

    REQUIRE(a_int == a_int);
    REQUIRE(b_int == b_int);
    REQUIRE(c_int == c_int);
    REQUIRE(a_d == a_d);
    REQUIRE(b_d == b_d);
    REQUIRE(c_d == c_d);
    REQUIRE(d_d == d_d);
    REQUIRE(e_d == e_d);
    REQUIRE(f_d == f_d);
    REQUIRE(g_d == g_d);
    REQUIRE(a_f == a_f);
    REQUIRE(b_f == b_f);
    REQUIRE(c_f == c_f);
    REQUIRE(d_f == d_f);
    REQUIRE(e_f == e_f);
    REQUIRE(f_f == f_f);
    REQUIRE(g_f == g_f);

    Complex<int> a_t;
    Complex<double> b_t;
    Complex<float> c_t;
    a_t = 5, b_t = 6.5, c_t = 7.5;
    REQUIRE(a_t == 5);
    REQUIRE(b_t == 6.5);
    REQUIRE(c_t == 7.5);
    a_t = {5, 5}, b_t = {6.5, 6.5}, c_t = {7.5, 7.5};
  }
  SECTION("Addition check") {
    Complex<int> a_int(5, 2);
    Complex<int> b_int(3, -3);
    Complex<int> c_int = a_int+b_int;

    REQUIRE(c_int.GetReal() == 8);
    REQUIRE(c_int.GetImaginary() == -1);

    a_int+=b_int;

    REQUIRE(a_int.GetReal() == 8);
    REQUIRE(a_int.GetImaginary() == -1);
  }
}