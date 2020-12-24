#include <thread>
#include <tuple>
#include <iostream>
#include <chrono>
#include <cassert>
#include <vector>
#include <cstdint>
#include <future>
#include <random>
#include <fstream>

class DenseMat {
 public:
  DenseMat(int32_t rows = 0, int32_t cols = 0)
      : rows_(rows), cols_(cols), data_(rows * cols) {}

  DenseMat(int32_t rows, int32_t cols, const std::vector<int32_t> &data)
      : rows_(rows), cols_(cols), data_(data) {
    assert((int32_t) data.size() == rows * cols);
  }

  int32_t Rows() const {
    return rows_;
  }

  int32_t Cols() const {
    return cols_;
  }

  const int32_t &operator()(int row, int col) const {
    return data_[row * cols_ + col];
  }

  int32_t &operator()(int row, int col) {
    return data_[row * cols_ + col];
  }

  bool operator==(const DenseMat &other) const {
    if (other.Rows() != Rows() || other.Cols() != Cols()) {
      return false;
    }

    for (int i = 0; i < Rows(); i++) {
      for (int j = 0; j < Cols(); j++) {
        if (this->operator()(i, j) != other(i, j)) {
          return false;
        }
      }
    }

    return true;
  }

  bool operator!=(const DenseMat &other) const {
    return !(*this == other);
  }

 private:
  int32_t rows_;

  int32_t cols_;

  std::vector<int32_t> data_;
};

DenseMat ReadMat(std::ifstream &input) {
  int32_t rows, cols;
  input >> rows >> cols;

  std::vector<int32_t> data;
  data.reserve(rows * cols);

  for (size_t i = 0; i < data.size(); i++) {
    int v;
    input >> v;

    data.push_back(v);
  }

  return DenseMat(rows, cols, data);
}

#include "matmul.h"

DenseMat SimpleMul(const DenseMat &a, const DenseMat &b) {
  DenseMat res(a.Rows(), b.Cols());

  for (int i = 0; i < a.Rows(); i++) {
    for (int j = 0; j < b.Cols(); j++) {
      for (int k = 0; k < a.Cols(); k++) {
        res(i, j) += a(i, k) * b(k, j);
      }
    }
  }

  return res;
}

template<class Generator>
DenseMat RandomMat(int32_t rows, int32_t cols, Generator &gen) {
  std::uniform_int_distribution<> dis(-1000, 1000);
  std::vector<int32_t> data(rows * cols);
  for (size_t i = 0; i < data.size(); i++) {
    data[i] = dis(gen);
  }

  return DenseMat(rows, cols, data);
}

template<class Func, class ... Args>
std::tuple<int32_t, DenseMat> BenchmarkFunc(Func f, Args &&... args) {
  std::chrono::steady_clock::time_point
      start = std::chrono::steady_clock::now();
  auto res = f(std::forward<Args>(args)...);
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

  return {std::chrono::duration_cast<std::chrono::milliseconds>(
      end - start).count(), res};
}

int main(int argc, char **argv) {
  std::mt19937 gen(12312);

  std::cerr << "Generating random matrices..." << std::endl;
  auto a = RandomMat(100, 1000, gen);
  auto b = RandomMat(1000, 100, gen);

  std::cerr << "Start benchmarking..." << std::endl;

  int32_t trivial_ms;
  DenseMat ans;
  std::tie(trivial_ms, ans) = BenchmarkFunc(SimpleMul, a, b);

  const int32_t best_thread_count =
      12; // ThreadSanitizer??? // std::thread::hardware_concurrency();
  auto aaaa = std::thread::hardware_concurrency();
  int32_t last_time = 1e9;
  for (int tcount = 1; tcount <= 5; tcount++) {
    int32_t mul_ms;
    DenseMat mat_res;
    std::tie(mul_ms, mat_res) = BenchmarkFunc(MatMulParal, a, b, tcount);

    assert(mat_res == ans);

    std::cerr << "Thread count: " << tcount << std::endl;
    std::cerr << "Time, ms: " << mul_ms << std::endl;

    if (tcount <= best_thread_count) {
      assert(mul_ms < last_time);
      last_time = mul_ms;
    }
  }

  assert(last_time < 140);

  std::cerr << "Trivial ms: " << trivial_ms << std::endl;
  std::cout << 1 << std::endl;
}