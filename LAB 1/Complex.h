//
// Library for complex numbers
//
#include <iostream>
#include <cmath>
#include "Rational.h"
#ifndef PMI_T_3_H_CPP_LAB_1_COMPLEX_H_
#define PMI_T_3_H_CPP_LAB_1_COMPLEX_H_
template<typename T>
class Complex {
 public:
  Complex() = default;

  Complex(T valid) {
    this->real = valid;
    this->imaginary = 0;
  }

  Complex(Rational<T> valid, Rational<T> alleged) {
    this->real = valid;
    this->imaginary = alleged;
  }

  Complex(const Complex &fresh) {
    this->real = fresh.real;
    this->imaginary = fresh.imaginary;
  }

  [[nodiscard]] auto GetReal() const {
    return real;
  }
  void SetReal(Rational<T> r) {
    this->real = r;
  }
  [[nodiscard]] auto GetImaginary() const {
    return imaginary;
  }
  void SetImaginary(Rational<T> i) {
    this->imaginary = i;
  }

  // сложение
  Complex operator+(const Complex &fresh) const {
    return Complex(this->real + fresh.real, this->imaginary + fresh.imaginary);
  }

  // вычитание
  Complex operator-(const Complex &fresh) const {
    return Complex(this->real - fresh.real, this->imaginary - fresh.imaginary);
  }

  // умножение
  Complex operator*(const Complex &fresh) const {
    return Complex(real * fresh.real - imaginary * fresh.imaginary,
                   real * fresh.imaginary + imaginary * fresh.real);
  }

  // деление
  Complex operator/(const Complex &fresh) const {
    Complex temp;

    auto r = fresh.real * fresh.real + fresh.imaginary * fresh.imaginary;
    temp.real = (real * fresh.real + imaginary * fresh.imaginary) / r;
    temp.imaginary = (imaginary * fresh.real - real * fresh.imaginary) / r;

    return temp;
  }

  // оператор =
  Complex &operator=(const Complex &fresh) = default;

  // оператор ==
  bool operator==(const Complex &fresh) const {
    return this->real == fresh.real && this->imaginary == fresh.imaginary;
  }

  // оператор !=
  bool operator!=(const Complex &fresh) const {
    return !(*this == fresh);
  }

  // оператор +=
  Complex &operator+=(const Complex &fresh) {
    return *this = *this + fresh;
  }

  // оператор -=
  Complex &operator-=(const Complex &fresh) {
    return *this = *this - fresh;
  }

  // оператор *=
  Complex &operator*=(const Complex &fresh) {
    return *this = *this * fresh;
  }

  // оператор /=
  Complex &operator/=(const Complex &fresh) {
    auto r = fresh.real * fresh.real + fresh.imaginary * fresh.imaginary;
    auto re = (this->real * fresh.real + this->imaginary * fresh.imaginary) / r;
    this->imaginary =
        (this->imaginary * fresh.real - this->real * fresh.imaginary) / r;
    this->real = re;
    return *this;
  }

  // оператор -Complex
  Complex operator-() const {
    return Complex(-real, -imaginary);
  }

  // Возведение в натуральную степень
  Complex operator^(unsigned int num) const {
    Complex temp;
    temp.real = this->real;
    temp.imaginary = this->imaginary;
    for (unsigned int i = 1; i < num; i++) {
      temp = this->operator*(Complex(temp.real, temp.imaginary));
    }
    return temp;
  }

//   Модуль комплексного числа
  [[nodiscard]] T abs() {
    auto temp = this->real * this->real + this->imaginary * this->imaginary;
    return std::sqrt(temp.toDouble());
  }

  [[nodiscard]] T arg() const {
    if (this->real == 0 && this->imaginary == 0) return 0;
    auto arg_result = Rational<T>(this->imaginary / this->real).Atan();
    if (this->real < 0 && this->imaginary >= 0) {
      arg_result += M_PI;
    } else if (this->real < 0 && this->imaginary < 0) {
      arg_result -= M_PI;
    }
    return arg_result;
  }

  // оператор <<
  friend std::ostream &operator<<(std::ostream &output, const Complex &fresh) {
    if (fresh.real == 0 && fresh.imaginary == 0) {
      output << 0;
    } else if (fresh.real != 0 && fresh.imaginary == 0) {
      output << fresh.real;
    } else if (fresh.real == 0) {
      if (fresh.imaginary == 1) {
        output << "i";
      } else if (fresh.imaginary == -1) {
        output << "-i";
      } else {
        output << fresh.imaginary << "i";
      }
    } else {
      if (fresh.imaginary == 1) {
        output << "(" << fresh.real << "+" << "i)";
      } else if (fresh.imaginary == -1) {
        output << "(" << fresh.real << "-i)";
      } else if (fresh.imaginary > 0) {
        output << "(" << fresh.real << "+" << fresh.imaginary << "i)";
      } else {
        output << "(" << fresh.real << fresh.imaginary << "i)";
      }
    }

    return output;
  }

 private:
  Rational<T> real, imaginary;  // действительная и мнимая части
};

#endif //PMI_T_3_H_CPP_LAB_1_COMPLEX_H_
