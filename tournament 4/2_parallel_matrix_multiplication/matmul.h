//
// Created by User on 24.12.2020.
//

#ifndef PMI_T_3_H_CPP_TOURNAMENT_4_2_PARALLEL_MATRIX_MULTIPLICATION_MATMUL_H_
#define PMI_T_3_H_CPP_TOURNAMENT_4_2_PARALLEL_MATRIX_MULTIPLICATION_MATMUL_H_
#include <vector>

void AlgoMul(const DenseMat &a, const DenseMat &b,
             DenseMat *res, int lhs, int rhs) {
  for (int i = lhs; i < rhs; i++) {
    for (int j = 0; j < b.Cols(); j++) {
      for (int k = 0; k < a.Cols(); k++) {
        (*res)(i, j) += a(i, k) * b(k, j);
      }
    }
  }
}

DenseMat MatMulParal(const DenseMat &a, const DenseMat &b, int thread_count) {
  DenseMat res(a.Rows(), b.Cols());

  size_t block_size = a.Rows() / thread_count;

  std::vector<std::thread> threads(thread_count - 1);
  int block_start = 0;
  for (auto &i : threads) {
    int block_end = block_start;
    block_end += block_size;
    i = std::thread(AlgoMul, std::ref(a),
                    std::ref(b), &res, block_start, block_end);
    block_start = block_end;
  }
  AlgoMul(a, b, &res, block_start, a.Rows());
  for (auto &t : threads)
    t.join();
  return res;
}

#endif  // PMI_T_3_H_CPP_TOURNAMENT_4_2_PARALLEL_MATRIX_MULTIPLICATION_MATMUL_H_
