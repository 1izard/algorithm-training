#include <fstream>
#include <stdio.h>
#include <vector>

#define M 10007

using namespace std;

typedef vector<int> vi;
typedef vector<vi> mat;

int N;

mat mul(mat &A, mat &B) {
  mat C(A.size(), vi(B[0].size()));
  for (int i = 0; i < A.size(); ++i) {
    for (int j = 0; j < B[0].size(); ++j) {
      for (int k = 0; k < B.size(); ++k) {
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
      }
    }
  }
  return C;
}

mat pow(mat A, int n) {
  mat B(A.size(), vi(A.size()));
  for (int i = 0; i < A.size(); ++i) {
    B[i][i] = 1;
  }
  while (n > 0) {
    if (n & 1) {
      B = mul(B, A);
    }
    A = mul(A, A);
    n >>= 1;
  }
  return B;
}

int main() {
  ifstream ifs("../testset/blocks/test2.txt");
  ifs >> N;
  mat A(3, vi(3));
  A[0][0] = 2;
  A[0][1] = 1;
  A[0][2] = 0;
  A[1][0] = 2;
  A[1][1] = 2;
  A[1][2] = 2;
  A[2][0] = 0;
  A[2][1] = 1;
  A[2][2] = 2;
  A = pow(A, N);
  printf("%d\n", A[0][0]);
}