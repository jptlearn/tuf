#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 1. Find largest element in the array
// int sortArr(vector<int> &arr) {
  // sort(arr.begin(), arr.end());
  // return arr[arr.size() - 1];
// }

int findLargestElement(int arr[], int n) {
  int max = arr[0];
  for (int i = 0; i < n; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
}

// 2. Second smallest and second largest element in the array
// void getElements(int arr[], int n) {
//   if (n==0 || n==1) {
//     cout << 1 << " " << -1 << endl;
//   }
//   sort(arr, arr + n);
//   int small = arr[1];
//   int large = arr[n - 1];
//   cout << "Second smallest is " << small << endl;
//   cout << "Second largest is " << large << endl;
// }

void getElements(int arr[], int n) {
  if (n ==0 || n ==1) {
    cout << -1 << " " << -1 << endl;
  }
  int small = INT_MAX, second_small = INT_MAX;
  int large = INT_MIN, second_large = INT_MIN;
  int i;
  for (i = 0; i < n; i++) {
    small = min(small, arr[i]);
    large = max(large, arr[i]);
  }
  for (i = 0; i < n; i++) {
    if(arr[i] <second_small && arr[i]!=small) {
      second_small = arr[i];
    }
    if(arr[i] > second_large && arr[i]!=large) {
      second_large = arr[i];
    }
  }
  cout << "Second largest is " << second_large << endl;
  cout << "Second smallest is " << second_small << endl;
}

int secondLargest(vector<int> arr, int n) {
  int large = INT_MIN;
  int sLarge = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    if(arr[i] > large) {
      sLarge = large;
      large = arr[i];
    } else if(arr[i] > sLarge && arr[i] != large) {
      sLarge = arr[i];
    }
  }
  return sLarge;
}

int secondSmallest(vector<int> arr, int n) {
  int small = INT_MAX;
  int sSmall = INT_MAX;
  for (int i = 0; i < n; i++) {
    if(arr[i] < small) {
      sSmall = small;
      small = arr[i];
    } else if(arr[i] < sSmall && arr[i] != small) {
      sSmall = arr[i];
    }
  }
  return sSmall;
}

vector<int> getSecondOrderElements(int n, vector<int> a) {
  int sLargest = secondLargest(a, n);
  int sSmallest = secondSmallest(a, n);
  return {sLargest, sSmallest};
}

int main() {
  vector<int> arr1 = {2, 5, 1, 3, 0};
  vector<int> arr2 = {8, 10, 5, 7, 9};
  vector<int> res1 = getSecondOrderElements(arr1.size(), arr1);
  vector<int> res2 = getSecondOrderElements(arr2.size(), arr2);
  for(int x: res1)
    cout << x << " ";
  cout << endl;
  for (int x : res2)
    cout << x << " ";
  cout << endl;

  return 0;
}