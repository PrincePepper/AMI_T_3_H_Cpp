//
// Created by User on 19.12.2020.
//

#ifndef PMI_T_3_H_CPP_TOURNAMENT_4_3_QUEUE_SOLUTION_HPP_
#define PMI_T_3_H_CPP_TOURNAMENT_4_3_QUEUE_SOLUTION_HPP_
#include <utility>
#include <queue>
#include <mutex>

template<class T>
class Queue {
 public:
  T Pop() {
    std::lock_guard<std::mutex> lock(mutex_);
    auto res = std::move(data.front());
    data.pop();
    return res;
  }
  size_t Size() {
    std::lock_guard<std::mutex> lock(mutex_);
    return data.size();
  }
  template<typename U>
  void Push(U value) {
    std::lock_guard<std::mutex> lock(mutex_);
    data.push(std::move(value));
  }
  template<typename... U>
  void Emplace(U &&... args) {
    std::lock_guard<std::mutex> lock(mutex_);
    data.push(T(std::forward<U>(args)...));
  }

 private:
  std::queue<T> data;

  mutable std::mutex mutex_;
};

#endif  // PMI_T_3_H_CPP_TOURNAMENT_4_3_QUEUE_SOLUTION_HPP_
