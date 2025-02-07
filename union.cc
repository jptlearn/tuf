#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<int> unionArr(int arr1[], int arr2[], int n1, int n2) {
  set<int> st;
  for (int i = 0; i < n1; i++) {
    st.insert(arr1[i]);
  }
  for (int i = 0; i < n2; i++) {
    st.insert(arr2[i]);
  }
  // int k = st.size();
  // int temp[k];
  // int index = 0;
  // for (auto it : st) {
  //   temp[index] = it;
  //   index++;
  // }
  // for (int i = 0; i < k; i++) {
  //   cout << temp[i] << " ";
  // }
  // cout << endl;
  vector<int> result(st.begin(), st.end());
  return result;
}

int main() {
  int arr1[] = {1, 2, 3, 2, 3, 1};
  int arr2[] = {1, 4, 5, 5, 6};

  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  vector<int> union_result = unionArr(arr1, arr2, n1, n2);
  cout << "Union of arrays" << endl;
  for (int num: union_result) {
    cout << num << " ";
  }

    return 0;
}