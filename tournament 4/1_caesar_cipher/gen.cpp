#include <iostream>
#include <fstream>

using namespace std;

int main2(int argc, char *argv[]) {
  const int test_length = std::stoi(argv[1]);
  constexpr size_t buf_size = 1000000;
  string buf(buf_size, '\0');

  srand(1);
  ofstream test_file("input.txt");
  for (int i = 0; i < test_length; ++i) {
    if (i && !(i % buf_size))
      test_file << buf;
    buf[i % buf_size] = 'a' + rand() % 26;
  }
  if (!(test_length % buf_size))
    test_file << buf;
  else
    test_file << string(buf.begin(), buf.begin() + test_length % buf_size);

  return 0;
}