#include <iostream>
using namespace std;

int main() {
  // int var = 8;
  // int *ptr = &var;
  // *ptr = 10;
  // cout << var << endl;

  char *buffer = new char[8];
  memset(buffer, 0, 8);

  delete[] buffer;
  return 0;
}