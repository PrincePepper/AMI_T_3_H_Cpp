//
// Created by User on 11.11.2020.
//

#ifndef PMI_T_3_H_CPP_TOURNAMENT_2_3_FIXEDALLOCATOR_FIXED_ALLOCATOR_H_
#define PMI_T_3_H_CPP_TOURNAMENT_2_3_FIXEDALLOCATOR_FIXED_ALLOCATOR_H_
#include <vector>

template<typename T>
class FixedAllocator {
 public:
  explicit FixedAllocator(std::uint64_t page_size) :
      page_allocator_(sizeof(T) * page_size), size(page_size) {
    T *temp = static_cast<T *>(page_allocator_.Allocate());
    for (size_t i = 0; i < size; i++) memory.push_back(&temp[i]);
  }
  T *Allocate() {
    if (memory.size() == 0) {
      T *temp = static_cast<T *>(page_allocator_.Allocate());
      for (size_t i = 0; i < size; i++) memory.push_back(&temp[i]);
    }
    T *r = memory.back();
    memory.pop_back();
    return r;
  }
  void Deallocate(T *p) {
    memory.push_back(p);
  }

  [[nodiscard]] const PageAllocator &InnerAllocator() const noexcept {
    return page_allocator_;
  }

 private:
  PageAllocator page_allocator_;

  std::vector<T *> memory;

  size_t size;
};

#endif  // PMI_T_3_H_CPP_TOURNAMENT_2_3_FIXEDALLOCATOR_FIXED_ALLOCATOR_H_
