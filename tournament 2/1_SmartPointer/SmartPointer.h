#pragma once

#include <memory>
#include <utility>
#include "Test.h"

namespace smart_pointer {
// `exception` class definition
class exception : std::exception {
  using base_class = std::exception;
  using base_class::base_class;
};

// `SmartPointer` class declaration
template<
    typename T,
    typename Allocator
>
class SmartPointer {
  // don't remove this macro
  ENABLE_CLASS_TESTS;

 public:
  using value_type = T;

  explicit SmartPointer(value_type *other = nullptr) {
    if (other == nullptr)
      core = nullptr;
    else
      core = new Core(other);
  }

  // copy constructor
  SmartPointer(const SmartPointer &other) {
    if (other.core != nullptr)
      core = other.core;
    else
      core = nullptr;
    if (core != nullptr)
      core->count_owr++;
  }

  // move constructor
  SmartPointer(SmartPointer &&other) noexcept {
    core = std::move(other.core);
    other.core = nullptr;
  }

  // copy assigment
  SmartPointer &operator=(const SmartPointer &other) {
    this->~SmartPointer();
    core = other.core;
    if (core != nullptr)core->count_owr++;
    return *this;
  }

  // move assigment
  SmartPointer &operator=(SmartPointer &&other) {
    this->~SmartPointer();
    core = std::move(other.core);
    other.core = nullptr;
    return *this;
  }

  //
  SmartPointer &operator=(value_type *other) {
    this->~SmartPointer();
    if (other == nullptr)
      core = nullptr;
    else
      core = new Core(other);
    return *this;
  }

  ~SmartPointer() {
    if (core != nullptr) {
      if (core->count_owr <= 1)
        delete core;
      else
        core->count_owr--;
    }
  }

  // return reference to the object of class/type T
  // if SmartPointer contains nullptr throw `SmartPointer::exception`
  value_type &operator*() {
    if (core == nullptr || core->P == nullptr)
      throw smart_pointer::exception();
    else
      return *core->P;
  }

  const value_type &operator*() const {
    if (core == nullptr || core->P == nullptr)
      throw smart_pointer::exception();
    else
      return *core->P;
  }

  // return pointer to the object of class/type T
  value_type *operator->() const {
    return get();
  }

  value_type *get() const {
    if (core == nullptr)
      return nullptr;
    else
      return core->P;
  }

  // if pointer == nullptr => return false
  operator bool() const {
    if (core == nullptr || core->P == nullptr)
      return false;
    else
      return true;
  }

  decltype(auto) getCore() const {
    return static_cast<void *>(core);
  }
  // if pointers points to the same address or both null => true
  template<typename U, typename AnotherAllocator>
  bool operator==(const SmartPointer<U, AnotherAllocator> &other) const {
    return getCore() == other.getCore();
  }

  // if pointers points to the same address or both null => false
  template<typename U, typename AnotherAllocator>
  bool operator!=(const SmartPointer<U, AnotherAllocator> &other) const {
    return !(SmartPointer::operator==(other));
  }

  // if smart pointer contains non-nullptr => return count owners
  // if smart pointer contains nullptr => return 0
  std::size_t count_owners() const {
    if (this->core == nullptr) {
      return 0;
    } else {
      return core->count_owr;
    }
  }

 private:
  // класс Core хранит указатель на объект, на который надо хранить указатель,
  // а сами смартпоинтеры хранят указатели на Core
  class Core {
   public:
    explicit Core(value_type *P) : P(P), count_owr(1) {}
    ~Core() {
      if (P != nullptr)
        delete P;
    }

    value_type *P;

    size_t count_owr;
  };

  Core *core;
};
}  // namespace smart_pointer
