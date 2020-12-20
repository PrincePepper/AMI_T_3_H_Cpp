//
// Created by User on 20.12.2020.
//

#ifndef PMI_T_3_H_CPP_TOURNAMENT_4_1_CAESAR_CIPHER_CAESAR_ENCRYPT_H_
#define PMI_T_3_H_CPP_TOURNAMENT_4_1_CAESAR_CIPHER_CAESAR_ENCRYPT_H_
#include <thread>
#include <vector>
#include <algorithm>
#include <string>

using stditerator = std::string::iterator;

void CesarAlgo(stditerator first, stditerator last) {
  for_each(first, last, [](char &c) {
    c = 'a' + (c + 3 - 'a') % 26;
  });
}

void CaesarEncrypt(string *s) {
  size_t num_threads = thread::hardware_concurrency();
  size_t block_size = s->size() / num_threads;
  vector<thread> threads(num_threads - 1);
  stditerator block_start = s->begin();

  for (size_t i = 0; i < num_threads - 1; i++) {
    stditerator block_end = block_start;
    advance(block_end, block_size);
    threads[i] = thread(CesarAlgo, block_start, block_end);
    block_start = block_end;
  }

  CesarAlgo(block_start, s->end());

  for (auto &t : threads)
    t.join();
}

#endif  // PMI_T_3_H_CPP_TOURNAMENT_4_1_CAESAR_CIPHER_CAESAR_ENCRYPT_H_
