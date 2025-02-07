// #include <iostream>
// #include <cstdlib>  // for malloc, free
// using namespace std;

// int main() {
//   int n;
//   cout << "Enter size of array: ";
//   cin >> n;

//   // Allocate memory for n integers using malloc
//   int* arr = (int*)malloc(n * sizeof(int));

//   if (arr == NULL)
//   {
//     cout << "Memory allocation failed" << endl;
//     return 1;
//   }

//   // Fill array with values
//   for (int i = 0; i < n; i++) {
//     arr[i] = i + 1;
//   }

//   // Print array
//   for (int i = 0; i < n; i++) {
//     cout << arr[i] << " ";
//   }

//   // Free the allocated memory
//   free(arr);

//   return 0;
// }

// #include <iostream>
// #include <cstdlib>  // for calloc, free
// using namespace std;

// int main() {
//   int n;
//   cout << "Enter size of array: ";
//   cin >> n;

//   // Allocate memory for n integers using calloc (initializes to 0)
//   int* arr = (int*)calloc(n, sizeof(int));

//   if (arr == NULL) {
//     cout << "Memory allocation failed" << endl;
//     return 1;
//   }

//   // Print array (will show all zeros initially)
//   for (int i = 0; i < n; i++) {
//     cout << arr[i] << " ";
//   }

//   // Free the allocated memory
//   free(arr);

//   return 0;
// }

// #include <iostream>
// #include <cstdlib>  // for calloc, free
// using namespace std;

// int main() {
//   int n;
//   cout << "Enter size of array: ";
//   cin >> n;

//   // Allocate memory for n integers using calloc (initializes to 0)
//   int* arr = (int*)calloc(n, sizeof(int));

//   if (arr == NULL) {
//     cout << "Memory allocation failed" << endl;
//     return 1;
//   }

//   // Print array (will show all zeros initially)
//   for (int i = 0; i < n; i++) {
//     cout << arr[i] << " ";
//   }

//   // Free the allocated memory
//   free(arr);

//   return 0;
// }


#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Enter the size of the array: " << endl;
  cin >> n;

  // Using new for single element
  int *num = new int;
  *num = 10;
  cout << "Single element: " << *num << endl;

  // Using new for array
  int *arr = new int[n];
  
  // Fill array
  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }

  // Print array
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}