// Insertion Sort
// technique: Takes an element and places it in its correct order

#include <iostream>
#include <algorithm>
using namespace std;

void insertionSort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    int j = i;
    while(j > 0 && arr[j-1] > arr[j]) {
      int temp = arr[j - 1];
      arr[j - 1] = arr[j];
      arr[j] = temp;
      j--;
    }
  }
}

void recursive_insertion_sort (int arr[], int i, int n) {
  if(i == n)
    return;

  int j = i;
  while(j>0 && arr[j-1] > arr[j]) {
    int temp = arr[j - 1];
    arr[j - 1] = arr[j];
    arr[j] = temp;
  }
  recursive_insertion_sort(arr, i + 1, n);
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  insertionSort(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}