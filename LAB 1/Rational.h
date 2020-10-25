//Library for rational numbers
//Based on: https://www.boost.org/doc/libs/1_55_0/libs/rational/rational.html

#define EPSILON 0.00000001
#ifndef PMI_T_3_H_CPP_LAB_1_RATIONAL_H_
#define PMI_T_3_H_CPP_LAB_1_RATIONAL_H_

#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>

template<typename T>
class Rational {
 public:
  typedef T int_type;

  //// Constructors
  Rational() { // Zero
    this->numerator = 0;
    this->denominator = 0;
  }
  [[maybe_unused]] explicit Rational(T n) { // Equal to n/1
    this->numerator = n;
    this->denominator = 1;
  }
  Rational(T n, T d) { // General case (n/d)
    this->numerator = n;
    this->denominator = d;
    reduce(n, d);
  }

  //// Assignment from I
  Rational<T> &operator=(const Rational<T> &temp) = default;

  //// In addition to the following operators, all of the "obvious" derived
  //// operators are available - see operators.hpp

  //// Unary operators
  Rational operator+(const Rational<T> &r) const {
    this->numerator = this->numerator * r.denominator + r.numerator *
        this->denom;
    this->denominator = this->denominator * r.denominator;
    reduce();
    return Rational<T>(this->numerator, this->denominator);
  }

  Rational operator-(const Rational<T> &r) const {
    T temp_n = this->numerator * std::lcm(this->denominator, r.denominator)
        / this->denominator -
        r.numerator * std::lcm(this->denominator, r.denominator)
            / r.denominator;
    T temp_d = std::lcm(this->denominator, r.denominator);
    return Rational(temp_n, temp_d);
  }

  Rational operator/(const Rational<T> &r) const {
    return Rational<T>(this->numerator * r.denominator, this->denominator
        * r.numerator);
  }
  Rational operator*(const Rational &r) const {
    return Rational<T>(this->numerator * r.numerator,
        this->denominator * r.denominator);
  }

  //// Arithmetic operators
  Rational &operator+=(const Rational<T> &r) const {
    return *this = *this + r;
  }
  Rational &operator-=(const Rational<T> &r) const {
    return *this = *this - r;
  }
  Rational &operator*=(const Rational<T> &r) const {
    return *this = *this * r;
  }
  Rational &operator/=(const Rational<T> &r) const {
    return *this = *this / r;
  }

  //// Comparison operators
  bool operator==(const Rational<T> &r) const {
    return (std::fabs(this->numerator - r.numerator) < EPSILON)
        && (std::fabs(this->denominator, r.denominator) < EPSILON);
  }
  Rational<T> operator-() const {
    return Rational<T>(-this->numerator, this->denominator);
  }

  bool operator!=(const Rational<T> &r) const {
    return !this->operator==(r);
  }

  bool operator>(const Rational<T> &r) const {
    return this->numerator * r.denominator > r.numerator * this->denominator;
  }

  bool operator<(const Rational<T> &r) const {
    return r > *this;
  }

  bool operator>=(const Rational<T> &r) const {
    return *this > r || *this == r;
  }

  bool operator<=(const Rational<T> &r) const {
    return *this < r || *this == r;
  }


  Rational operator^(int num) const {
    Rational temp;
    temp.numerator = this->numerator;
    temp.denominator = this->denominator;
    for (int i = 1; i < num; i++) {
      temp = this->operator*(Rational(temp.numerator, temp.denominator));
    }
    return temp;
  }

  friend std::ostream &operator<<(std::ostream &out, const Rational<T> &r) {
    if (r.numerator == r.denominator) { out << 1; }
    else {
      out << std::to_string(r.numerator) + "/" + std::to_string(r.denominator);
    }
    return out;
  }
 private:
  // Representation
  T numerator = 0;
  T denominator = 0;

  void reduce(T a, T b) {
    auto gcd = std::gcd(a, b);
    this->numerator /= gcd;
    this->numerator /= gcd;
  }
};

//// Reversed order operators for - and / between (types convertible to) I and rational
//template<typename T, typename I>
//inline Rational<T> operator/(I i, const Rational<T> &r);
//template<typename T, typename I>
//inline Rational<T> operator-(I i, const Rational<T> &r);

//// Absolute value
//template<typename T>
//Rational<T> abs(const Rational<T> &r);

//// Type conversion
//template<typename T, typename I>
//T rational_cast(const Rational<I> &r);

#endif //PMI_T_3_H_CPP_LAB_1_RATIONAL_H_
