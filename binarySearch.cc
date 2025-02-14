#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int n, int target) {
  int low = 0;
  int high = n - 1;
  while(low <= high) {
    int mid = (low + high) / 2;
    if(arr[mid] == target)
      return mid;
    else if(target > arr[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int binaryRecursiveSearch(int arr[], int low, int high, int target) {
  if (low > high) {
    return -1;
  }
  int mid = (low + high) / 2;
  if(arr[mid] == target)
    return mid;
  else if(target > arr[mid])
    return binaryRecursiveSearch(arr, mid + 1, high, target);
  else
    return binaryRecursiveSearch(arr, low, mid - 1, target);
}

int binarySearch(int arr[], int low, int high, int target) {
  while(low <= high){
    int mid = (low + high) / 2;
    if (arr[mid] == target)
      return mid;
    if(target < arr[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}

int binarySearchRecur(int arr[], int low,int high,int target) {
  if(low > high)
    return -1;
  int mid = (low + high) / 2;
  if(arr[mid] == target) {
    return mid;
  } else if (target < arr[mid]) {
    return binarySearchRecur(arr, low, mid - 1, target);
  } else {
    return binarySearchRecur(arr, mid + 1, high, target);
  }
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int n = sizeof(arr) / sizeof(arr[0]);
  int target = 3;
  // int targetIndex = binarySearch(arr, 8, target);
  int targetIndex = binaryRecursiveSearch(arr, 0, n - 1, target);
  if (targetIndex == -1)
  {
    cout << "the target is not in the array" << endl;
  }
  else
  {
    cout << "the target is present in the array" << endl;
  }

  return 0;
}