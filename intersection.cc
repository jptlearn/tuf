#include <vector>
#include <iostream>
using namespace std;

void intersection(int arr1[], int arr2[], int n1, int n2) {
  vector<bool> visited(n2, false);
  vector<int> temp;
  for (int i = 0; i < n1; i++)
  {
    for (int j = 0; j < n2; j++) {
      if(arr1[i] == arr2[j] && visited[j] == 0) {
        temp.push_back(arr2[j]);
        visited[j] = true;
        break;
      }
      if(arr2[j] > arr1[i])
        return;
    }
  }
  for(auto it: temp) {
    cout << it << " ";
  }
  cout << endl;
}

void intersection1(int arr1[], int arr2[], int n1, int n2){
  int i = 0;
  int j = 0;
  vector<int> ans;
  while (i < n1 && j < n2) {
    if(arr1[i] < arr2[j]) {
      i++;
    }
    else if (arr2[j] < arr1[i])
    {
      j++;
    }
    else
    {
      ans.push_back(arr1[i]);
      i++;
      j++;
    }
  }
}

int main() {
  int arr1[] = {1, 2, 2, 3, 4, 5, 6};
  int arr2[] = {1, 2, 2, 3, 4, 5, 7};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  intersection1(arr1, arr2, n1, n2);

  return 0;
}