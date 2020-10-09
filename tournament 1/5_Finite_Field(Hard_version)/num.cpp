//
// Created by Semen Sereda on 01.10.2020.
//

#include "num.h"
#include <cstdint>
Num::Num(int value, int modulo) : value(value % modulo), modulo(modulo) {}

Num &Num::operator=(const Num &other) {
  value = other.value;
  modulo = other.modulo;
  return *this;
}

Num Num::operator+(const Num &other) {
  int64_t temp = ((int64_t) value + (int64_t) other.value);
  return Num(static_cast<int>(temp % modulo), modulo);
}

Num Num::operator-(const Num &other) {
  int64_t temp;
  if ((value - other.value) < 0) {
    temp = modulo + (value - other.value);
  } else {
    temp = value - other.value;
  }
  return Num(temp, modulo);
}

Num Num::operator*(const Num &other) {
  int64_t temp = (int64_t) value * (int64_t) other.value;
  return Num(static_cast<int>(temp % modulo), modulo);
}

Num Num::operator+(int num) {
  int64_t temp = (int64_t) value + (int64_t) num;
  return Num(static_cast<int>(temp % modulo), modulo);
}

Num Num::operator-(int num) {
  int64_t temp;
  if ((value - num) < 0) {
    temp = modulo + (value - num);
  } else {
    temp = value - num;
  }
  return Num(temp, modulo);
}

Num Num::operator*(int num) {
  int64_t temp = (int64_t) value * (int64_t) num;
  return Num(static_cast<int>(temp % modulo), modulo);
}

Num &Num::operator+=(const Num &other) {
  return *this = *this + other;
}

Num &Num::operator-=(const Num &other) {
  return *this = *this - other;
}

Num &Num::operator*=(const Num &other) {
  return *this = *this * other;
}

Num &Num::operator+=(int num) {
  return *this = *this + num;
}

Num &Num::operator-=(int num) {
  return *this = *this - num;
}

Num &Num::operator*=(int num) {
  return *this = *this * num;
}

