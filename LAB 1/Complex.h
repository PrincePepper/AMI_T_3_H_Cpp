//
// Created by User on 11.10.2020.
//
#include <iostream>
#include <cmath>

#ifndef PMI_T_3_H_CPP_LAB_1_COMPLEX_H_
#define PMI_T_3_H_CPP_LAB_1_COMPLEX_H_

class Complex {
 public:
  Complex() = default;

  Complex(double valid) {
    real = valid;
  }

  Complex(double valid, double alleged) {
    real = valid;
    imaginary = alleged;
  }

  Complex(const Complex &fresh) {
    real = fresh.real;
    imaginary = fresh.imaginary;
  }

  [[nodiscard]] double GetReal() const {
    return real;
  }
  void SetReal(double real) {
    this->real = real;
  }
  [[nodiscard]] double GetImaginary() const {
    return imaginary;
  }
  void SetImaginary(double imaginary) {
    this->imaginary = imaginary;
  }

  ~Complex() {
  }

  // сложение
  Complex operator+(const Complex &fresh) const {
    return Complex(real + fresh.real, imaginary + fresh.imaginary);
  }

  // вычитание
  Complex operator-(const Complex &fresh) const {
    return Complex(real - fresh.real, imaginary - fresh.imaginary);
  }

  // умножение
  Complex operator*(const Complex &fresh) const {
    return Complex(real * fresh.real - imaginary * fresh.imaginary,
        real * fresh.imaginary + imaginary * fresh.real);
  }

  // деление
  Complex operator/(const Complex &fresh) const {
    Complex temp;

    double r = fresh.real * fresh.real + fresh.imaginary * fresh.imaginary;
    temp.real = (real * fresh.real + imaginary * fresh.imaginary) / r;
    temp.imaginary = (imaginary * fresh.real - real * fresh.imaginary) / r;

    return temp;
  }

  // оператор =
  Complex &operator=(const Complex &fresh) = default;

  // оператор ==
  bool operator==(const Complex &fresh) const {
    if (std::fabs(this->real - fresh.real) <
        std::numeric_limits<double>::epsilon()
        && std::fabs(this->imaginary - fresh.imaginary) <
            std::numeric_limits<double>::epsilon()) {
      return true;
    } else {
      return false;
    }
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
    double re;
    double r = fresh.real * fresh.real + fresh.imaginary * fresh.imaginary;
    re = (this->real * fresh.real + this->imaginary * fresh.imaginary) / r;
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

  // Модуль комплексного числа
  [[nodiscard]] double abs() const {
    return sqrt(real * real + imaginary * imaginary);
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
        output << "(" << fresh.real << "i)";
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

  // оператор >>
  friend std::istream &operator>>(std::istream &input, Complex &fresh) {
    input >> fresh.real >> fresh.imaginary;
    return input;
  }

 private:
  double real = 0, imaginary = 0;  // действительная и мнимая части
};

#endif //PMI_T_3_H_CPP_LAB_1_COMPLEX_H_
