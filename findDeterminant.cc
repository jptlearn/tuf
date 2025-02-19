#include <iostream>
#include <vector>

int determinant(std::vector<std::vector<int>> &matrix, int n) {
  if (n==1) 
  {
    return matrix[0][0];
  }
  if (n==2) 
  {
    return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
  }

  int det = 0;
  std::vector<std::vector<int>> subMatrix(n, std::vector<int>(n, 0));

  for (int x = 0; x < n; x++) {
    int subi = 0;
    for (int i = 0; i < n; i++) {
      int subj = 0;
      for (int j = 0; j < n; j++) {
        if(j==x)
          continue; // Skip the current column
        subMatrix[subi][subj] = matrix[i][j];
        subj++;
      }
      subi++;
    }
    det += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(subMatrix, n - 1);
  }
  return det;
}

int main(){
  std::vector<std::vector<int>> matrix = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
    {13, 14, 15, 16}};

  int det = determinant(matrix, matrix.size());
  std::cout << "Determinant of given matrix: " << det << std::endl;
  return 0;
}