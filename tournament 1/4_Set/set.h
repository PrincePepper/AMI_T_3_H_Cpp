//
// Created by semyo on 01.10.2020.
//

#ifndef PMI_T_3_H_CPP_TOURNAMENT_1_4_SET_SET_H_
#define PMI_T_3_H_CPP_TOURNAMENT_1_4_SET_SET_H_

#include <vector>

class Set {
 public:
  Set Union(const Set &temp) {
    Set temp_set(mass);
    for (auto i : temp.mass) {
      if (!Contains(i)) temp_set.Add(i);
    }
    return temp_set;
  }
  Set Intersection(const Set &temp) {
    Set temp_set(mass);
    for (auto i : temp.mass) {
      if (!temp.Contains(i)) temp_set.Remove(i);
    }
    return temp_set;
  }
  Set Difference(const Set &) {

  }
  Set SymmetricDifference(const Set &) {

  }
  void Add(int64_t temp) {
    if (Contains(temp)) return;
    mass.push_back(temp);
  }
  void Remove(int64_t temp) {
    mass.erase(std::remove(mass.begin(), mass.end(), temp), mass.end());
  }
  bool Contains(int64_t temp) const {
    return std::find(mass.begin(), mass.end(), temp) != mass.end();
  }
  std::vector<int64_t> Data() {
  }

  Set(const std::vector<int64_t> &mass) {
    for (auto i : mass)
      Add(i);
  }
 private:
  std::vector<int64_t> mass;
};

#endif //PMI_T_3_H_CPP_TOURNAMENT_1_4_SET_SET_H_
