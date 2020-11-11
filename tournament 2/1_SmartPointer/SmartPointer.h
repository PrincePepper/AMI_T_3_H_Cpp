#pragma once

#include <memory>
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

  SmartPointer(value_type * = nullptr);

  // copy constructor
  SmartPointer(const SmartPointer &);

  // move constructor
  SmartPointer(SmartPointer &&);

  // copy assigment
  SmartPointer &operator=(const SmartPointer &);

  // move assigment
  SmartPointer &operator=(SmartPointer &&);

  //
  SmartPointer &operator=(value_type *);

  ~SmartPointer();

  // return reference to the object of class/type T
  // if SmartPointer contains nullptr throw `SmartPointer::exception`
  value_type &operator*();
  const value_type &operator*() const;

  // return pointer to the object of class/type T
  value_type *operator->() const;

  value_type *get() const;

  // if pointer == nullptr => return false
  operator bool() const;

  // if pointers points to the same address or both null => true
  template<typename U, typename AnotherAllocator>
  bool operator==(const SmartPointer<U, AnotherAllocator> &) const;

  // if pointers points to the same address or both null => false
  template<typename U, typename AnotherAllocator>
  bool operator!=(const SmartPointer<U, AnotherAllocator> &) const;

  // if smart pointer contains non-nullptr => return count owners
  // if smart pointer contains nullptr => return 0
  std::size_t count_owners() const;

 private:
  class Core;
  Core *core;
};
}