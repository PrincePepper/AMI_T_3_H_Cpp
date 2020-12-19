#include "solution.hpp"

#include <iostream>
#include <thread>
#include <functional>
#include <type_traits>

using namespace std;

class LotsOfData {
 public:
  LotsOfData() {}
  explicit LotsOfData(int value) : value(value) {}

  LotsOfData(const LotsOfData &) = delete;

  LotsOfData(LotsOfData &&rhs) {
    this->value = rhs.value;
    rhs.value = -1;
  }

  LotsOfData &operator=(const LotsOfData &) = delete;

  LotsOfData &operator=(LotsOfData &&rhs) {
    this->value = rhs.value;
    rhs.value = -1;
    return *this;
  }
  ~LotsOfData() {}

  int value;
};

Queue<LotsOfData> q;

void push(int n) {
  while (n > 0) {
    q.Push(LotsOfData(n));
    --n;
  }
}

void emplace(int n) {
  while (n > 0) {
    q.Emplace(n);
    --n;
  }
}

void pop(int n) {
  while (n > 0) {
    if (q.Size() > 0) {
      q.Pop();
      --n;
    }
  }
}

// **********************
class DestroyedOnMove {
  friend bool destroyed(const DestroyedOnMove &);

 private:
  bool destroyed = false;

 public:
  DestroyedOnMove() = default;

  DestroyedOnMove(const DestroyedOnMove &) = default;

  DestroyedOnMove(DestroyedOnMove &&other) : destroyed(other.destroyed) {
    other.destroyed = true;
  }
};

bool destroyed(const DestroyedOnMove &d) { return d.destroyed; }

class HasOnlyMove {
 public:
  HasOnlyMove(HasOnlyMove &&) = default;
};

template<typename Q, typename Dummy = void>
struct check_only_move : std::false_type {};

template<typename Q>
struct check_only_move<Q,
                       std::void_t<decltype(std::declval<Q>().Push(HasOnlyMove{}))>>
    : std::true_type {
};

template<typename Q, typename Dummy = void>
struct check_const_ref_passing : std::false_type {};

template<typename Q>
struct check_const_ref_passing<Q,
                               std::void_t<decltype(std::declval<Q>().Push(std::declval<
                                   const int &>()))>> : std::true_type {
};
// **********************

int main() {
  // **********************
  if constexpr (!check_only_move<Queue<HasOnlyMove>>::value)
    (std::cout
        << "Your queue should work with objects which don't have copy constructor"
        << std::endl), exit(0);
  if constexpr (!check_const_ref_passing<Queue<int>>::value)
    (std::cout << "Your queue should work with const objects"
               << std::endl), exit(0);
  {
    DestroyedOnMove d;
    Queue<DestroyedOnMove> q;
    q.Push(d);
    if (destroyed(d))
      (std::cout << "Lvalue object passed to Push has been moved unexpectedly"
                 << std::endl), exit(0);
  }
  // **********************

  std::string query;
  std::cin >> query;
  if (query == "check") {
    while (std::cin >> query) {
      if (query == "push") {
        int value;
        std::cin >> value;
        q.Push(LotsOfData(value));
      }
      if (query == "emplace") {
        int value;
        std::cin >> value;
        q.Emplace(value);
      }
      if (query == "pop") {
        auto element = q.Pop();
        std::cout << element.value << " ";
      }
    }
  } else if (query == "thread_check") {
    int n;
    cin >> n;
    std::thread push_thread(std::bind(push, n / 2));
    std::thread emplace_thread(std::bind(emplace, n - n / 2));
    std::thread pop_thread(std::bind(pop, n));
    push_thread.detach();
    emplace_thread.detach();
    pop_thread.join();
    std::cout << 1 << std::endl;
  } else {
    std::cout << -1 << std::endl;
  }
}