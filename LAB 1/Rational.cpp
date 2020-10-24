#include "Rational.h"
#include <iostream>
using namespace std;
int main() {
  Rational<int> test(5, 3);
  Rational<int> test2;
  test2 = {1, 2};
  test = test - test2;
  cout << test;
}