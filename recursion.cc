#include <iostream>
#include <algorithm>
using namespace std;

// Recursion -> When a function calls itself until a specified condition is met
// if no stopping condition is mentioned in the code, it is called infinite recursion
// base condition and stopping condition

// print name n times using recursion

void printName(int i, int n) {
  if (i>n)
    return;
  cout << "Birendra" << endl;
  printName(i + 1, n);
}

void printToN(int i, int n) {
  if (i>n) {
    return;
  }
  cout << i << endl;
  printToN(i + 1, n);
}

void printTo1(int i, int n) {
  if (i<1) {
    return;
  }
  cout << i << endl;
  printTo1(i - 1, n);
}

void print1ToN(int i, int n) {
  if (i<1){
    return;
  }
  print1ToN(i - 1, n);
  cout << i << endl;
}

void printNTo1(int i, int n) {
  if(i>n) {
    return;
  }
  printNTo1(i+1, n);
  cout << i << endl;
}

void sumToN(int i, int sum) {
  if (i<1) {
    cout << sum << endl;
    return;
  }
  sumToN(i - 1, sum + i);
}

int sum(int n) {
  if(n==0) {
    return 0;
  }
  return n + sum(n - 1);
}

int factorial(int n) {
  if (n == 0)
    return 1;
  return n * factorial(n - 1);
}

void reverseArr(int i, int n, int arr[]) {
  // if (l >= r)
  //   return;
  // swap(arr[l], arr[r]);
  // reverseArr(l + 1, r - 1, arr);
  
  // single pointer
  if (i >= (n/2))
    return;
  swap(arr[i], arr[n - i - 1]);
  reverseArr(i + 1, n, arr);
}

bool checkPalindromeString(string str, int i, int n) {
  if(i>= n/2)
    return true;
  if (str[i] != str[n - i - 1])
  {
    return false;
  }
  return checkPalindromeString(str, i + 1, n);
}

int main() {
  // int n;
  // cin >> n;
  // printName(1, n);
  // printToN(1, 10);
  // printTo1(n, n);
  // printNTo1(1, n);
  // int arr[n];
  // for (int i = 0; i < n; i++) {
  //   cin >> arr[i];
  // }
  //   // sumToN(n, 0);
  // reverseArr(0, n, arr);
  string str = "MADAM";
  int n = str.length();
  if(checkPalindromeString(str, 0, n)) {
    cout << "Palindrome string" << endl;
  } else {
    cout << "Not a palindrome string" << endl;
  }

  return 0;
}