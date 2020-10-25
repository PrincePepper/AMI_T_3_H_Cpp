#include <cassert>
#include <iostream>
#include <vector>
#include <functional>

#include "num.h"
#include "num.cpp"

using namespace std;

int main() {
  {
    num a(1, 10);
    assert(a.value == 1);
    assert(a.modulo == 10);

    num b(2001, 10);
    assert(b.value == 1);
    assert(b.modulo == 10);
  }

  {
    num a(20000, 100);
    assert(a.value == 0);
    assert(a.modulo == 100);

    num b = a;
    assert(b.value == 0);
    assert(b.modulo == 0);
  }

  {
    num a(99, 100);
    assert(a.value == 99);
    assert(a.modulo == 100);

    num b = a;
    assert(b.value == 99);
    assert(b.modulo == 0);
  }
  cout << 1 << endl;
}