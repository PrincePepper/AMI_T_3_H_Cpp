//
// Created by semyo on 01.10.2020.
//

#ifndef PMI_T_3_H_CPP_TOURNAMENT_1_5_FINITE_FIELD_HARD_VERSION_NUM_H_
#define PMI_T_3_H_CPP_TOURNAMENT_1_5_FINITE_FIELD_HARD_VERSION_NUM_H_

class Num {
 public:
  Num(int value, int modulo);

  Num &operator=(const Num &other);

  Num operator+(const Num &other);
  Num operator-(const Num &other);
  Num operator*(const Num &other);
  Num operator+(int num);
  Num operator-(int num);
  Num operator*(int num);

  Num &operator+=(const Num &other);
  Num &operator-=(const Num &other);
  Num &operator*=(const Num &other);
  Num &operator+=(int num);
  Num &operator-=(int num);
  Num &operator*=(int num);

  int value;
  int modulo;
};

#endif //PMI_T_3_H_CPP_TOURNAMENT_1_5_FINITE_FIELD_HARD_VERSION_NUM_H_
