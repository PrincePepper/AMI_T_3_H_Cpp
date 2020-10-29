#include <iostream>
#include "Complex.h"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "complex"
using namespace std;

TEST_CASE("Complex numbers") {

  SECTION("creating a class and writing and comparing with itself") {
    Complex<int> a_int(5, 2);
    Complex<int> b_int(3, -3);
    Complex<int> c_int(3, 0);
    Complex<int> d_int(4);
    Complex<int> e_int = 7;
    a_int = a_int;
    b_int = b_int;
    c_int = c_int;

    REQUIRE(a_int == a_int);
    REQUIRE(b_int == b_int);
    REQUIRE(c_int == c_int);
    REQUIRE(d_int.GetReal() == 4);
    REQUIRE(d_int.GetImaginary() == 0);
    REQUIRE(e_int.GetReal() == 7);
    REQUIRE(e_int.GetImaginary() == 0);

    Complex<int> kopy = Complex<int>(8, 3);
    Complex<int> dCopy(kopy);
    REQUIRE(dCopy == kopy);
  }
  SECTION("Addition check") {
    Complex<int> a_int(5, 2);
    Complex<int> b_int(3, -3);
    Complex<int> c_int = a_int + b_int;

    REQUIRE(c_int.GetReal() == 8);
    REQUIRE(c_int.GetImaginary() == -1);

    a_int += b_int;

    REQUIRE(a_int.GetReal() == 8);
    REQUIRE(a_int.GetImaginary() == -1);

    a_int += b_int + a_int;
    REQUIRE(a_int.GetReal() == 19);
    REQUIRE(a_int.GetImaginary() == -5);
  }
  SECTION("Subtraction check") {
    Complex<int> a_int(5, 2);
    Complex<int> b_int(3, -3);
    Complex<int> c_int = a_int - b_int;

    REQUIRE(c_int.GetReal() == 2);
    REQUIRE(c_int.GetImaginary() == 5);

    a_int -= b_int;

    REQUIRE(a_int.GetReal() == 2);
    REQUIRE(a_int.GetImaginary() == 5);

    a_int -= b_int - a_int;
    REQUIRE(a_int.GetReal() == 1);
    REQUIRE(a_int.GetImaginary() == 13);
  }
  SECTION("Division check") {
    Complex<int> a_int(5, 2);
    Complex<int> b_int(3, -3);

    Complex<int> c_int = a_int / b_int;
    Rational<int> a_r(1, 2);
    Rational<int> b_r(7, 6);
    REQUIRE(c_int.GetReal() == a_r);
    REQUIRE(c_int.GetImaginary() == b_r);

    a_int /= b_int;

    REQUIRE(a_int.GetReal() == a_r);
    REQUIRE(a_int.GetImaginary() == b_r);
    a_r = {-41, 108};
    b_r = {1, 108};
    a_int /= b_int / a_int;
    REQUIRE(a_int.GetReal() == a_r);
    REQUIRE(a_int.GetImaginary() == b_r);
  }

  SECTION("Multiplication check") {
    Complex<int> a_int(5, 2);
    Complex<int> b_int(3, -3);

    Complex<int> c_int = a_int * b_int;
    REQUIRE(c_int.GetReal() == 21);
    REQUIRE(c_int.GetImaginary() == -9);

    a_int *= b_int;

    REQUIRE(a_int.GetReal() == 21);
    REQUIRE(a_int.GetImaginary() == -9);
    a_int *= b_int * a_int;
    REQUIRE(a_int.GetReal() == -54);
    REQUIRE(a_int.GetImaginary() == -2214);
  }

  SECTION("Comparison check") {
    Complex<int> a_int(5, 2);
    Complex<int> b_int(3, -3);
    if (a_int != b_int)
      b_int = a_int;
    REQUIRE(b_int.GetReal() == 5);
    REQUIRE(b_int.GetImaginary() == 2);
  }
  SECTION("Assignment of values") {
    Complex<int> a_int(5, 2);
    Complex<int> b_int(3, -3);
    a_int.SetReal(b_int.GetReal());
    a_int.SetImaginary(b_int.GetImaginary());
    REQUIRE(a_int.GetReal() == 3);
    REQUIRE(a_int.GetImaginary() == -3);
  }
  SECTION("Negation") {
    Complex<int> a_int(5, 2);
    Complex<int> b_int(-5, -2);
    a_int = -a_int;
    REQUIRE(a_int.GetReal() == b_int.GetReal());
    REQUIRE(a_int.GetImaginary() == b_int.GetImaginary());
  }

  SECTION("The construction in the natural degree") {
    Complex<int> a_int(5, 2);
    Complex<int> b_int;
    b_int = a_int ^ 2;
    REQUIRE(b_int.GetReal() == 21);
    REQUIRE(b_int.GetImaginary() == 20);
  }
  SECTION("Number module") {
    Complex<int> a_int(5, 2);
    std::complex<int> b_int(5, 2);
    auto b = a_int.abs();
    auto c = std::abs(b_int);
    REQUIRE(b == c);
  }

  SECTION("Response output") {
    Complex<int> a_int(5, 2);
    Complex<int> b_int(3, -3);
    Complex<int> c_int(0, 0);
    Complex<int> d_int(5, 0);
    Complex<int> e_int(0, 1);
    Complex<int> f_int(0, -1);
    Complex<int> g_int(0, 5);
    Complex<int> h_int(2, -1);
    Complex<int> v_int(3, 1);
    REQUIRE(cout << a_int << endl);
    REQUIRE(cout << b_int << endl);
    REQUIRE(cout << c_int << endl);
    REQUIRE(cout << a_int / b_int << endl);
    REQUIRE(cout << d_int << endl);
    REQUIRE(cout << e_int << endl);
    REQUIRE(cout << f_int << endl);
    REQUIRE(cout << g_int << endl);
    REQUIRE(cout << h_int << endl);
    REQUIRE(cout << v_int << endl);
  }

  SECTION("Long expressions") {
    Complex<int> a(13, 1);
    Complex<int> b(7, 6);
    Complex<int> c(7, -6);
    Complex<int> d(7, 6);
    auto ans=(a*b)/(c*d);

    REQUIRE(ans.GetReal()==1);
    REQUIRE(ans.GetImaginary()==1);
  }
}

TEST_CASE("Rational numbers") {

  SECTION("creating a class and writing and comparing with itself") {
    Rational<int> a_int(5, 2);
    Rational<int> b_int(3, -3);
    Rational<int> c_int(3, 2);
    Rational<int> d_int(4);
    Rational<int> e_int = 7;
    a_int = a_int;
    b_int = b_int;
    c_int = c_int;

    REQUIRE(a_int == a_int);
    REQUIRE(b_int == b_int);
    REQUIRE(c_int == c_int);
    REQUIRE(d_int.GetNumerator() == 4);
    REQUIRE(d_int.GetDenominator() == 1);
    REQUIRE(e_int.GetNumerator() == 7);
    REQUIRE(e_int.GetDenominator() == 1);

    Rational<int> kopy = Rational<int>(8, 3);
    Rational<int> dCopy(kopy);
    REQUIRE(dCopy == kopy);
  }
  SECTION("Addition check") {
    Rational<int> a_int(5, 2);
    Rational<int> b_int(3, -3);
    Rational<int> c_int = a_int + b_int;

    REQUIRE(c_int.GetNumerator() == 3);
    REQUIRE(c_int.GetDenominator() == 2);

    a_int += b_int;

    REQUIRE(a_int.GetNumerator() == 3);
    REQUIRE(a_int.GetDenominator() == 2);

    a_int += b_int + a_int;
    REQUIRE(a_int.GetNumerator() == 2);
    REQUIRE(a_int.GetDenominator() == 1);
  }

  SECTION("Subtraction check") {
    Rational<int> a_int(5, 2);
    Rational<int> b_int(3, -3);
    Rational<int> c_int = a_int - b_int;

    REQUIRE(c_int.GetNumerator() == 7);
    REQUIRE(c_int.GetDenominator() == 2);

    a_int -= b_int;

    REQUIRE(a_int.GetNumerator() == 7);
    REQUIRE(a_int.GetDenominator() == 2);

    a_int -= b_int - a_int;
    REQUIRE(a_int.GetNumerator() == 8);
    REQUIRE(a_int.GetDenominator() == 1);
  }

  SECTION("Division check") {
    Rational<int> a_int(5, 2);
    Rational<int> b_int(3, -3);

    Rational<int> c_int = a_int / b_int;
    REQUIRE(c_int.GetNumerator() == -5);
    REQUIRE(c_int.GetDenominator() == 2);

    a_int /= b_int;

    REQUIRE(a_int.GetNumerator() == -5);
    REQUIRE(a_int.GetDenominator() == 2);
    a_int /= b_int / a_int;
    REQUIRE(a_int.GetNumerator() == -25);
    REQUIRE(a_int.GetDenominator() == 4);
  }

  SECTION("Multiplication check") {
    Rational<int> a_int(5, 2);
    Rational<int> b_int(3, -3);

    Rational<int> c_int = a_int * b_int;
    REQUIRE(c_int.GetNumerator() == 5);
    REQUIRE(c_int.GetDenominator() == -2);

    a_int *= b_int;

    REQUIRE(a_int.GetNumerator() == 5);
    REQUIRE(a_int.GetDenominator() == -2);
    a_int *= b_int * a_int;
    REQUIRE(a_int.GetNumerator() == 25);
    REQUIRE(a_int.GetDenominator() == -4);
  }

  SECTION("Comparison check") {
    Rational<int> a_int(5, 2);
    Rational<int> b_int(3, -3);
    if (a_int != b_int)
      b_int = a_int;
    REQUIRE(b_int.GetNumerator() == 5);
    REQUIRE(b_int.GetDenominator() == 2);
  }
  SECTION("Assignment of values") {
    Rational<int> a_int(5, 2);
    Rational<int> b_int(3, -3);
    a_int.SetNumerator(b_int.GetNumerator());
    a_int.SetDenominator(b_int.GetDenominator());
    REQUIRE(a_int.GetNumerator() == 1);
    REQUIRE(a_int.GetDenominator() == -1);
  }
  SECTION("Negation") {
    Rational<int> a_int(5, 2);
    Rational<int> b_int(-5, 2);
    a_int = -a_int;
    REQUIRE(a_int.GetNumerator() == b_int.GetNumerator());
    REQUIRE(a_int.GetDenominator() == b_int.GetDenominator());
  }

  SECTION("The construction in the natural degree") {
    Rational<int> a_int(5, 2);
    Rational<int> b_int;
    b_int = a_int ^ 2;
    REQUIRE(b_int.GetNumerator() == 25);
    REQUIRE(b_int.GetDenominator() == 4);
  }
  SECTION("Getting double") {
    Rational<int> a_int(5, 2);
    auto b_int = a_int.toDouble();
    REQUIRE(b_int == 2.5);
  }

  SECTION("check which is more") {
    Rational<int> a_int(5, 2);
    Rational<int> b_int(4, -3);
    REQUIRE(a_int > b_int);
  }

  SECTION("Response output") {
    Rational<int> a_int(5, 2);
    Rational<int> b_int(3, -3);
    Rational<int> c_int(0, 0);//выдаст ошибку
    Rational<int> d_int(4, 0);//выдаст ошибку
    Rational<int> e_int(0, 4);
    Rational<int> f_int(4, 4);
    Rational<int> g_int(4, 1);
    Rational<int> h_int(4, -1);
    Rational<int> j_int(-4, 1);

    REQUIRE(cout << a_int << endl);
    REQUIRE(cout << b_int << endl);
    REQUIRE(cout << a_int / b_int << endl);

    REQUIRE(cout << c_int << endl);
    REQUIRE(cout << d_int << endl);

    REQUIRE(cout << e_int << endl);
    REQUIRE(cout << f_int << endl);
    REQUIRE(cout << g_int << endl);
    REQUIRE(cout << h_int << endl);
    REQUIRE(cout << j_int << endl);
  }

  SECTION("Long expressions") {
    Rational<int> a(2, 1);
    Rational<int> b(25, 8);
    Rational<int> c(1, 4);
    Rational<int> d(3, 10);
    auto ans=(a*b-c)/d;
    REQUIRE(ans==20);
  }
}