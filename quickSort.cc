#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Quick Sort -> Divide and conquer
// technique: Pick a pivot and place it in its correct place in the sorted array
// and smaller on the left and larger on the right

int partition(vector<int> &arr, int low, int high) {
  int pivot = arr[low];
  int i = low;
  int j = high;
  while(i<j) {
    while(arr[i] <= pivot && i <= high-1) {
      i++;
    }
    while(arr[j] > pivot && j >= low + 1) {
      j--;
    }
    if (i<j)
      swap(arr[i], arr[j]);
  }
  swap(arr[low], arr[j]);
  return j;
}

void qs(vector<int> &arr, int low, int high) {
  if(low < high) {
    int pIndex = partition(arr, low, high);
    qs(arr, low, pIndex - 1);
    qs(arr, pIndex + 1, high);
  }
}

vector<int> quickSort(vector<int> arr) {
  qs(arr, 0, arr.size() - 1);
  return arr;
}

int main() {
  vector<int> arr = {4, 5, 2, 6, 7, 9, 1, 3};
  int n = arr.size();
  cout << "Before Using quick sort: " << endl;
  for (int i = 0; i < n;  i++) {
    cout << arr[i] << " ";
  }

  arr = quickSort(arr);
  cout << "After using quick sort: " << endl;
  for (int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}