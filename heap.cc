// // Heap
// #include <iostream>
// #include <vector>
// #include <algorithm> // For std::swap
// using namespace std;

// class MinHeap {
//   private:
//     vector<int> heap;  // Vector to store heap elements

//     // Helper function: returns the parent index of index i
//     int parent(int i) {
//       return (i - 1) / 2;
//     }

//     // Helper function: returns the left child index of index i
//     int leftChild(int i) {
//       return 2 * i + 1;
//     }

//     // Helper function: returns the right child index of index i
//     int rightChild(int i) {
//       return 2 * i + 2;
//     }

//     void heapifyDown(int i) {
//       int smallest = i;
//       int left = leftChild(i);
//       int right = rightChild(i);

//       if(left < heap.size() && heap[left] < heap[smallest]) {
//         smallest = left;
//       }

//       if(right < heap.size() && heap[right] < heap[smallest]) {
//         smallest = right;
//       }
//     }

//   public:
//   // Constructor (default)
//     MinHeap() {};

//     // Function to insert a new element into the heap
//     void insert(int value) {
//       // Step 1: Add the new element at tne end of the vector
//       heap.push_back(value);

//       // Step 2: "Bubble-up" the new element to maintain the min-heap property
//       int i = heap.size() - 1; // Get the index of the newly added element
//       // While not at the root and parent's value is greater than the current element:
//       while(i != 0 && heap[parent(i)] > heap[i]) {
//         // Swap the current element with its parent
//         swap(heap[i], heap[parent(i)]);
//         // Update i to the parent's index
//         i = parent(i);
//       }
//     }

//     // Delete the root
//     void deleteRoot() {
//       if(heap.size() == 0) {
//         cout << "Heap is empty. " << endl;
//         return;
//       }

//       heap[0] = heap.back();  // Replace root with the last element
//       heap.pop_back(); // Replace the last element
//       heapifyDown(0); // Restore the Min-Heap property
//     }

//     // Function to print the heap ( for debugging and demonstration )
//     void printHeap() {
//       for (int i = 0; i < heap.size(); i++){
//         cout << heap[i] << " ";
//       }
//       cout << endl;
//     }
// };


// int main() {
//   MinHeap h;

//   // Insert some element into the heap
//   h.insert(3);
//   h.insert(2);
//   h.insert(15);
//   h.insert(5);
//   h.insert(4);
//   h.insert(45);
//   h.insert(1);
//   h.insert(20);
//   h.insert(0);
//   h.insert(90);
//   h.insert(56);

//   cout << "Min-Heap elements: ";
//   h.printHeap();

//   return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class HeapSort {
  private:
  void heapify(vector<int> &arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child
    
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
      largest = left;
    }

    if (right < n && arr[right] > arr[largest]){
      largest = right;
    }

    // If larges is not root
    if (largest != i) {
      swap(arr[i], arr[largest]);
      heapify(arr, n, largest); // Recursively heapify the affected subtree
    }
  }
  
  public:
  void heapSort(vector<int> &arr) {
    int n = arr.size();

    // Build Max-Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
      heapify(arr, n, i);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i >= 1; i--) {
      swap(arr[0], arr[i]); // Move the current root (max element) to the end
      heapify(arr, i, 0); // Heapify the reduced heap
    }
  }
};

int main() {
  vector<int> arr = {12, 11, 13, 5, 6, 7};
  HeapSort hs;
  cout << "unsorted array: ";
  for(int num: arr) {
    cout << num << " ";
  }
  cout << endl;

  hs.heapSort(arr);

  cout << "Sorted array: ";
  for (int num: arr) {
    cout << num << " ";
  }

  cout << endl;

  return 0;
}
