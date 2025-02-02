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

void printPattern9(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n-i-1; j++) {
      cout << " " << " ";
    }
    for (int k = 0; k < 2 * i + 1; k++) {
      cout << "*" << " ";
    }
    for (int l = 0; l < n - i - 1; l++) {
      cout << " " << " ";
    }
    for (int x = 0; x < i + 1; x++) {
      cout << " " << " ";
    }
    for (int y = 0; y < 2 * (n-i) - 1; y++) {
      cout << "*" << " ";
    }
    for (int z = 0; z < i + 1; z++) {
      cout << " " << " ";
    }
    cout << endl;
  }

}

void printPattern10(int n) {
  for (int i = 1; i <= 2 * n - 1; i++) {
    int stars = i;
    if (i>n)
      stars = 2 * n - i;
    for (int j = 1; j <= stars; j++)
    {
      cout << "*" << " ";
    }
    cout << endl;
  }
}

void printPattern11(int n) {
  for (int i = 1; i <= n; i++) {
    int ele = (i%2 == 0) ? 0: 1;
    for (int j = 0; j < i; j++) {
      cout << ele << " ";
      ele = 1 - ele;
    }
    cout << endl;
  }
}

void printPattern12(int n) {
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << j << " ";
    }
    for (int k = 1; k < n - i; k++) {
      cout << " " << " ";
    }
    for (int l = 1; l < n - i; l++) {
      cout << " " << " ";
    }
    for (int m = i; m > 0; m--) {
      cout << m << " ";
    }
    cout << endl;
  }
}

void printPattern13(int n) {
  int ele = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++) {
      cout << ele << " ";
      ele++;
    }
    cout << endl;
  }
}

void printPattern14(int n) {
  for (int i = 0; i < n; i++) {
    for (char ch = 'A'; ch <= 'A' + i; ch++){
      cout << ch << " ";
    }
    cout << endl;
  }
}

void printPattern15(int n) {
  for (int i = 1; i <= n; i++) {
    for (char ch = 'A'; ch <= 'A' + n - i; ch++) {
      cout << ch << " ";
    }
    cout << endl;
  }
}

void printPattern16(int n) {
  char ch = 'A';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++) {
      cout << ch << " ";
    }
    ch++;
    cout << endl;
  }
}

void printPattern17(int n) {
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n-i; j++) {
      cout << " " << " ";
    }
    for (char ch = 'A'; ch < 'A' + i; ch++){
      cout << ch << " ";
    }
    
    for (int k = i-1; k > 0; k--) {
      char ch = 'A' + k - 1;
      cout << ch << " ";
    }
    cout << endl;
  }
}

void printPattern18(int n) {
  for (int i = n; i >= 0; i--) {
    for (char ch = 'A' + i; ch <'A' + n; ch++) {
      cout << ch << " ";
    }
    cout << endl;
  }
}

void printPattern19(int n) {
  int iniS = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n-i; j++) {
      cout << "*" << " ";
    }
    for (int k = 0; k < iniS; k++)
    {
      cout << " " << " ";
    }
    for (int l = 0; l < n - i; l++) {
      cout << "*" << " ";
    }
    iniS += 2;
    cout << endl;
  }

  iniS = 2 * n - 2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++) {
      cout << "*" << " ";
    }
    for (int k = 0; k < iniS; k++) {
      cout << " " << " ";
    }
    for (int l = 0; l < i + 1; l++) {
      cout << "*" << " ";
    }
    iniS -= 2;
    cout << endl;
  }
}

void printPattern21(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
      {
        cout << "*" << " ";
      } else {
        cout << " " << " ";
      }
    }
    cout << endl;
  }
}

void printPattern22(int n) {
  for (int i = 0; i < 2 * n - 1; i++) {
    for (int j = 0; j < 2 * n - 1; j++) {
      int top = i;
      int bottom = j;
      int right = (2 * n - 2) - j;
      int left = (2 * n - 2) - i;

      cout << (n - min(min(top, bottom), min(left, right))) << " ";
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
  // printPattern8(n);
  // printPattern9(n);
  // printPattern10(n);
  // printPattern11(n);
  // printPattern12(n);
  // printPattern13(n);
  // printPattern14(n);
  // printPattern15(n);
  // printPattern16(n);
  // printPattern17(n);
  // printPattern18(n);
  // printPattern19(n);
  // printPattern19(n);
  // printPattern21(n);
  printPattern22(n);
  return 0;
}