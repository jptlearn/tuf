#include <iostream>
using namespace std;

void printPattern1(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << "*" << " ";
    }
    cout << endl;
  }
}

void printPattern2(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cout << "*" << " ";
    }
    cout << endl;
  }
}

void printPattern3(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= i + 1; j++) {
      cout << j << " ";
    }
    cout << endl;
  }
}

void printPattern4(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      cout << i << " ";
    }
    cout << endl;
  }
}

void printPattern5(int n) {
  for (int i = 0; i <= n; i++) {
    for (int j = n; j > i; j--) {
      cout << "*" << " ";
    }
    cout << endl;
  }
}

void printPattern6(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= n - i; j++) {
      cout << j << " ";
    }
    cout << endl;
  }
}

void printPattern7(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n-i-1; j++){
      cout << " " << " ";
    }
    for (int k = 0; k < 2 * i+1; k++) {
      cout << "*" << " ";
    }
    for (int l = 0; l < n - i - 1; l++) {
      cout << " " << " ";
    }
    cout << endl;
  }
}

void printPattern8(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++) {
      cout << " " << " ";
    }
    for (int k = 0; k < 2 * (n-i) - 1; k++) {
      cout << "*" << " ";
    }
    for (int l = 0; l < i + 1; l++) {
      cout << " " << " ";
    }
    cout << endl;
  }
}

int main() {
  int n = 5;
  // printPattern1(n);
  // printPattern2(n);
  // printPattern3(n);
  // printPattern4(n);
  // printPattern5(n);
  // printPattern6(n);
  // printPattern7(n);
  printPattern8(n);
  return 0;
}