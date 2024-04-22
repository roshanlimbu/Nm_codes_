#include <stdio.h>

#define N 3 // Number of equations

void forward_elimination(float mat[N][N + 1]) {
  for (int k = 0; k < N - 1; k++) {
    for (int i = k + 1; i < N; i++) {
      float factor = mat[i][k] / mat[k][k];
      for (int j = k; j <= N; j++) {
        mat[i][j] -= factor * mat[k][j];
      }
    }
  }
}

void back_substitution(float mat[N][N + 1], float sol[N]) {
  for (int i = N - 1; i >= 0; i--) {
    sol[i] = mat[i][N];
    for (int j = i + 1; j < N; j++) {
      sol[i] -= mat[i][j] * sol[j];
    }
    sol[i] /= mat[i][i];
  }
}

int main() {
  float mat[N][N + 1];
  float sol[N]; // Array to store solution

  printf("Enter the augmented matrix (A|B) for %d equations:\n", N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= N; j++) {
      printf("Enter element mat[%d][%d]: ", i, j);
      scanf("%f", &mat[i][j]);
    }
  }

  forward_elimination(mat);
  back_substitution(mat, sol);

  printf("\nSolution:\n");
  for (int i = 0; i < N; i++) {
    printf("x%d = %.2f\n", i + 1, sol[i]);
  }

  return 0;
}
