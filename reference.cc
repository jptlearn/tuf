#include <iostream>
using namespace std;

void increment(int* value) {
  (*value)++;
  cout << *value << endl;
}

int main() {
  int a = 5;
  int &ref = a;
  ref = 2;
  increment(&a); // this is reference
  cout << a << endl;
}