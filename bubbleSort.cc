// Bubble Sort
// technique: push the maximum to the last by adjacent swaps

#include <iostream>
#include <algorithm>
using namespace std;

// void bubbleSort(int arr[], int n) {
//   for (int i = 0; i <= n - 1; i++) {
//     for (int j = 0; j <= n - i - 1; j++) {
//       if(arr[j] > arr[j+1]) {
//         int temp = arr[j];
//         arr[j] = arr[j + 1];
//         arr[j + 1] = temp;
//       }
//     }
//   }
// }

void bubbleSort(int arr[], int n) {
  for (int i = n - 1; i >= 1; i--) {
    int didSwap = 0;
    for (int j = 0; j <= i - 1; j++)
    {
      if(arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        didSwap = 1;
      }
    }
    if (didSwap == 0) {
      break;
    }
    cout << "runs\n";
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  bubbleSort(arr, n);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}