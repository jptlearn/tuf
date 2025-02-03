#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

void countDigits(int n) {
  // brute force approach
  int counter = 1;
  while(n>0) {
    counter = counter + 1;
    n = n / 10;
  }
  cout << counter;
  
  // Optimal approach
  // int cnt = (int)(log10(n) + 1);
  // cout << cnt;
}

void reverseNumber(int n) {
  int reversedNum = 0;
  while (n > 0)
  {
    int lastDigit = n % 10;
    reversedNum = reversedNum * 10 + lastDigit;
    n = n / 10;
  }
  cout << reversedNum;
}

void checkPalindrome(int n) {
  // Palindrome -> It is a number that reads the same backward as forward.
  // eg. 1221, 1331, 4554 etc, are the palindrome number
  int numBackward = 0;
  int duplicate = n;
  while (n > 0)
  {
    int lastDigit = n % 10;
    numBackward = (numBackward * 10) + lastDigit;
    n = n / 10;
  }
  if(numBackward == duplicate) {
    cout << "it is palindrome" << endl;
  } else {
    cout << "it is not palindrome" << endl;
  }
}

void gcd(int n1, int n2) {
  // brute force approach
  // int gcd = 1;
  // for (int i = 1; i <= min(n1, n2); i++) {
  //   // check if i is a common factor of both n1 and n2
  //   if (n1 % i == 0 && n2 % i == 0) {
  //     gcd = i;
  //   }
  // }
  // cout << gcd;

  // // Optimal approach
  // for (int i = min(n1, n2); i > 0; i++) {
  //   if (n1 % i == 0 && n2 % i == 0) {
  //     cout << i << endl;
  //     return;
  //   }
  // }

  // Better Approach
  // Euclidean Algorithm is a method for finding the greatest common divisor of two
  // numbers. It operates on the principles that the GCD of two numbers remains the
  // same even if the smaller number is subtracted from the large number
  // initial euclidean formula is for a > b, gcd(a,b) = gcd(a-b,b);
  // we optimize this formula to , for a > b, gcd(a,b) = gcd(a%b,b);

  while(n1 > 0 && n2 > 0) {
    if(n1 > n2) {
      n1 = n1 % n2;
    } else {
      n2 = n2 % n1;
    }
  }
  if (n1 == 0) {
    cout << n2 << endl;
    return;
  }
  cout << n1 << endl;
}

void checkArmstrong(int n) {
  int sum = 0;
  int duplicate = n;
  while(n>0) {
    int lastDigit = n % 10;
    sum = sum + (lastDigit*lastDigit*lastDigit);
    n = n / 10;
  }
  if (sum == duplicate) {
    cout << "It is armstrong number." << endl;
  } else {
    cout << "It is not armstrong number" << endl;
  }
}

void printDivisors(int n) {
  // brute force
  // for (int i = 1; i < n; i++) {
  //   if (n % i == 0) {
  //     cout << i << endl;
  //   }
  // }

  // optimal approach
  vector<int> ls;
  for (int i = 1; i*i<=n; i++)
  {
    if (n%i==0) {
      ls.push_back(i);
      if ((n / i) != i)
      {
        ls.push_back(n / i);
      }
    }
  }
  sort(ls.begin(), ls.end());
  for(auto it: ls) {
    cout << it << endl;
  }
}

void checkPrime(int n) {
  // a number which is divisible by 1 and itself, this is wrong definition
  // a number which has exactly 2 factors, 1 and itself
  // brute force
  // int cnt = 0;
  // for (int i = 0; i < n; i++) {
  //   if(n%i == 0) {
  //     cnt++;
  //   }
  // }
  // if(cnt ==2) {
  //   cout << "it is prime" << endl;
  // } else {
  //   cout << "is is not prime." << endl;
  // }

  // Optimal Approach
  int cnt = 0;
  for (int i = 0; i * i <= n; i++) {
    if(n % i == 0) {
      cnt++;
      if((n/i) != i) {
        cnt++;
      }
    }
  }
  if (cnt == 2) {
    cout << "it is prime" << endl;
  } else {
    cout << "it is not a prime number" << endl;
  }

}

int main() {
  int n = 3221223;
  // countDigits(n);
  // reverseNumber(n);
  // checkPalindrome(n);
  printDivisors(36);
  return 0;
}