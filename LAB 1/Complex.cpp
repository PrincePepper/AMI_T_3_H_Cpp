//
// Created by User on 11.10.2020.
//
#include "Complex.h"
using namespace std;
int main() {
  Complex a(5, 2);
  Complex b(3, -3);
  b = b;
  cout << "a = " << a << "; b =" << b << endl;
  if (a != b) {
    cout << 2 << endl;
  }

  a += b;

  cout << "a = " << a << "; b =" << b << endl;

  Complex c = 5;

  cout << c << endl;
  cout << a + b << endl;
  cout << a * b << endl;
  c = a / b;
  cout << c << endl;
  a /= b;
  b = -b;
  cout << a << b << endl;
  a = b;
  if (a == b) cout << true << endl;
  cout << a << endl;
  b = a ^ 3;
  cout << a << b << endl;

  return 0;
}