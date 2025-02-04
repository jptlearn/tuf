#include <iostream>
#include <map>
using namespace std;


// Number Hashing
// int main() {
//   int n;
//   cin >> n;
//   int arr[n];
//   for (int i = 0; i < n; i++) {
//     cin >> arr[i];
//   }

//   // precompute
//   int hash[13] = {0};
//   for (int i = 0; i < n; i++) {
//     hash[arr[i]] += 1;
//   }

//     int q;
//   cin >> q;
//   while(q--) {
//     int number;
//     cin >> number;
//     // fetch
//     cout << hash[number] << endl;
//   }

//   return 0;
// }


// character hashing
// int main() {
//   string str;
//   cin >> str;

//   // precompute
//   int hash[256] = {0};
//   for (int i = 0; i<str.size(); i++) {
//     hash[str[i]]++;
//   }

//     int q;
//   cin >> q;
//   while(q--) {
//     char c;
//     cin >> c;
//     // fetch
//     cout << hash[c] << endl;
//   }

//   return 0;
// }

// Number hashing using unordered_map

// int main() {
//   int n;
//   cin >> n;
//   int arr[n];
//   for (int i = 0; i < n; i++) {
//     cin >> arr[i];
//   }

//   // precompute
//   map<int, int> mp;
//   for (int i = 0; i < n; i++) {
//     mp[arr[i]]++;
//   }

//   for (auto it: mp) {
//     cout << it.first << "->" << it.second << endl;
//   }
//   int q;
//   cin >> q;
//   while (q--) {
//     int number;
//     cin >> number;
//     // fetch
//     cout << mp[number] << endl;
//   }
// }

// void countFreq(int arr[], int n) {
//   vector<bool> visited(n, false);
//   for (int i = 0; i < n; i++) {
//     if (visited[i] == true) {
//       continue;
//     }
//     // Count frequency
//     int count = 1;
//     for (int j = i + 1; j < n; j++) {
//       if (arr[i] == arr[j]) {
//         visited[j] = true;
//         count++;
//       }
//     }
//     cout << arr[i] << " " << count << endl;
//   }
// }

// int main() {
//   int arr[] = {10, 5, 10, 25, 10, 5};
//   int n = sizeof(arr) / sizeof(arr[0]);
//   countFreq(arr, n);

//   return 0;
// }


void Frequency(int arr[], int n) {
  unordered_map<int, int> map;
  for (int i = 0; i < n; i++) {
    map[arr[i]]++;
  }
  for(auto x: map) {
    cout << x.first << " " << x.second << endl;
  }
}

int main() {
  int arr[] = {10, 5, 10, 15, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  Frequency(arr, n);

  return 0;
}