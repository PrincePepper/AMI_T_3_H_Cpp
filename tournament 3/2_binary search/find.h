//
// Created by User on 14.12.2020.
//

#ifndef PMI_T_3_H_CPP_TOURNAMENT_3_2_BINARY_SEARCH_FIND_H_
#define PMI_T_3_H_CPP_TOURNAMENT_3_2_BINARY_SEARCH_FIND_H_
template<typename T, typename Iterator>
Iterator FindIMPL(const T &v, Iterator first,
                  Iterator last, std::bidirectional_iterator_tag) {
  while (first != last) {
    if (*first == v) return first;
    first++;
  }
  return last;
}

template<typename T, typename Iterator>
Iterator FindIMPL(const T &v, Iterator first,
                  Iterator last, std::random_access_iterator_tag) {
  Iterator end = last;
  while (first != last) {
    Iterator middle = first + ((last - first) / 2);
    if (*middle < v) {
      first = middle + 1;
    } else {
      last = middle;
    }
  }
  if (*last == v) return last;
  return end;
}

template<typename T, typename Iterator>
Iterator Find(const T &value, Iterator first, Iterator last) {
  typedef typename std::iterator_traits<Iterator>::iterator_category category;
  return FindIMPL(value, first, last, category());
}

#endif  // PMI_T_3_H_CPP_TOURNAMENT_3_2_BINARY_SEARCH_FIND_H_
