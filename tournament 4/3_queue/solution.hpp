//
// Created by User on 19.12.2020.
//

#ifndef PMI_T_3_H_CPP_TOURNAMENT_4_3_QUEUE_SOLUTION_HPP_
#define PMI_T_3_H_CPP_TOURNAMENT_4_3_QUEUE_SOLUTION_HPP_

#include <queue>

template<typename T>
class Queue {
 public:
  T Pop() {
    auto res = std::move(data.front());
    data.pop();
    return res;
  }
  size_t Size() {
    return data.size();
  }
  template<typename U>
  void Push(U value) {
    data.push(std::move(value));
  }
  template<typename... U>
  void Emplace(U &&... args) {
    data.push(T(std::forward<U>(args)...));
  }

 private:
  std::queue<T> data;
};

#endif //PMI_T_3_H_CPP_TOURNAMENT_4_3_QUEUE_SOLUTION_HPP_
