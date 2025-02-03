#include <iostream>
#include <algorithm>
using namespace std;

// // solution 1: naive approach
// int main() {
//   int n = 5;
//   if (n == 0) {
//     cout << 0 << endl;
//   } else if (n == 1) {
//     cout << 0 << " " << 1 << endl;
//   } else {
//     int fib[n + 1];
//     fib[0] = 0;
//     fib[1] = 1;
//     for (int i = 2; i <= n; i++) {
//       fib[i] = fib[i - 1] + fib[i - 2];
//     }
//     cout << "fibonacci series up to " << n << "th term: " << endl;
//     for (int i = 0; i <= n; i++) {
//       cout << fib[i] << endl;
//     }
//   }
// }

// Solution 2: Space Optimized, we wont create extra fib[n+1] array
// int main() {
//   int n = 5;
//   if (n == 0){
//     cout << 0 << endl;
//   } else {
//     int secondLast = 0;
//     int last = 1;
//     cout << "The fibonacci series up to " << n << "th term" << endl;
//     cout << secondLast << " " << last << " ";
//     int curr;
//     for (int i = 2; i <= n; i++) {
//       curr = last + secondLast;
//       secondLast = last;
//       last = curr;
//       cout << curr << " ";
//     }
//   }
// }



// Solution 3: Recursive Method
int fibonacci(int n) {
  if(n <= 1) {
    return n;
  }
  int last = fibonacci(n - 1);
  int slast = fibonacci(n - 2);

  return last + slast;
}

int main() {
  int N = 4;
  cout << fibonacci(N) << endl;

  return 0;
}