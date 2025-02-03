#include <iostream>
#include <algorithm>
using namespace std;

// Example: Input: N = 5, arr[] = {5,4,3,2,1}
// Output: {1,2,3,4,5}


void printArray(int arr[], int n) {
  cout << "the reversed array is: " << endl;
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << endl;
  }
}

// Solution 1: Using the extra array
void reverseArray1(int arr[], int n) {
  int ans[n];
  for (int i = n - 1; i >= 0; i--) {
    ans[n - i - 1] = arr[i];
  }
  printArray(ans, n);
}

// Solution 2: Using pointer (space optimized)
void reverseArray2(int arr[], int n) {
  int p1 = 0, p2 = n - 1;
  while (p1 < p2) {
    swap(arr[p1], arr[p2]);
    p1++;
    p2--;
  }
  printArray(arr, n);
}

// Solution 3: Recursive method
void reverseArray3(int arr[], int start, int end) {
  if (start < end) {
    swap(arr[start], arr[end]);
    reverseArray3(arr, start + 1, end - 1);
  }
}

int main() {
  int n = 5;
  int arr[] = {5, 4, 3, 2, 1};
  reverseArray1(arr, n);

  return 0;
}