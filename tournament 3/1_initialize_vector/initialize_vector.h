//
// Created by User on 14.12.2020.
//

#ifndef PMI_T_3_H_CPP_TOURNAMENT_3_1_INITIALIZE_VECTOR_INITIALIZE_VECTOR_H_
#define PMI_T_3_H_CPP_TOURNAMENT_3_1_INITIALIZE_VECTOR_INITIALIZE_VECTOR_H_
#include <vector>

using std::vector;

template<typename T, typename V, typename D>
auto initialize_vector(V v, D d) {
  vector<T> vec(d, v);
  return vec;
}

template<typename T, typename V, typename D, typename... Args>
auto initialize_vector(V v, D d, Args... args) {
  vector<typeof(initialize_vector<T>(v, args...))>
      vec(d, initialize_vector<T>(v, args...));
  return vec;
}

#endif  // PMI_T_3_H_CPP_TOURNAMENT_3_1_INITIALIZE_VECTOR_INITIALIZE_VECTOR_H_
