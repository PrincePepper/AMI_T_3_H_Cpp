//
// Created by Semen Sereda on 14.12.2020.
//

#ifndef PMI_T_3_H_CPP_TOURNAMENT_3_1_INITIALIZE_VECTOR_INITIALIZE_VECTOR_H_
#define PMI_T_3_H_CPP_TOURNAMENT_3_1_INITIALIZE_VECTOR_INITIALIZE_VECTOR_H_
#include <vector>

template<typename V, typename D>
auto initialize_vector(V v, D d) {
  std::vector<decltype(v)> vec(d, v);
  return vec;
}

template<typename V, typename D, typename... Args>
auto initialize_vector(V v, D d, Args... args) {
  std::vector<decltype(initialize_vector(v, args...))>
      vec(d, initialize_vector(v, args...));
  return vec;
}

#endif  // PMI_T_3_H_CPP_TOURNAMENT_3_1_INITIALIZE_VECTOR_INITIALIZE_VECTOR_H_