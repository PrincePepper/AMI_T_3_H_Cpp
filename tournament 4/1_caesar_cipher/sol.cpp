#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main2() {
  ifstream input_file("input.txt");
  ofstream output_file("output.txt");
  string s;
  input_file >> s;
  for (char &c : s)
    c = 'a' + (c + 3 - 'a') % 26;
  output_file << s;
  return 0;
}