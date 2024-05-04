#include <math.h>
#include <stdio.h>

#define N 5

double f(double x) { return log(x); }

double divided_difference(double x[], double y[], int n, int i, int j) {
  if (j == 0) {
    return y[i];
  } else {
    return (divided_difference(x, y, n, i + 1, j - 1) -
            divided_difference(x, y, n, i, j - 1)) /
           (x[i + j] - x[i]);
  }
}

double newton_interpolation(double x[], double y[], int n, double xi) {
  double result = 0.0;
  for (int i = 0; i < n; i++) {
    double term = divided_difference(x, y, n, 0, i);
    for (int j = 0; j < i; j++) {
      term *= (xi - x[j]);
    }
    result += term;
  }
  return result;
}

int main() {
  double x[N] = {1, 2, 3, 4, 5}; // x values
  double y[N];                   // corresponding y values
  for (int i = 0; i < N; i++) {
    y[i] = f(x[i]); // calculate y values
  }
  double xi;
  printf("Enter the value for interpolation: ");
  scanf("%lf", &xi);

  double result = newton_interpolation(x, y, N, xi);
  printf("Interpolated value at %.2lf is %.2lf\n", xi, result);

  return 0;
}
