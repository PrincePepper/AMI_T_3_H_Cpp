//
// Created by semyo on 22.09.2020.
//

#ifndef PMI_T_3_H_CPP_NUM_H
#define PMI_T_3_H_CPP_NUM_H

#include <iostream>

class Num {
 public:
  Num(int value = 0, int modulo = 0);

  Num(const Num &other);

  int value;
  int modulo;
};

#endif //PMI_T_3_H_CPP_NUM_H
