//
// Created by semyo on 22.09.2020.
//

#include "num.h"

Num::Num(int value, int modulo) {
  this->modulo = modulo;
  this->value = value % modulo;
}

Num::Num(const Num &other) {
  this->value = other.value;
  this->modulo = 0;
}

