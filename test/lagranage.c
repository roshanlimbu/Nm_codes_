
#include <math.h> // for pow()
#include <stdio.h>

double LagrangePolynomial(double x, double x_data[], double y_data[], int n) {
  double result = 0.0;
  for (int i = 0; i < n; i++) {
    double product = 1.0;
    for (int j = 0; j < n; j++) {
      if (i != j) {
        product *= (x - x_data[j]) / (x_data[i] - x_data[j]);
      }
    }
    result += y_data[i] * product;
  }
  return result;
}

int main() {
  int n = 3;
  double x_data[] = {1, 4, 9};
  double y_data[] = {1, 2, 3};

  double target;
  printf("Enter a number to approximate square root: ");
  scanf("%lf", &target);

  double approx_sqrt = LagrangePolynomial(target, x_data, y_data, n);
  printf(
      "Approximate square root of %.2lf using Lagrange interpolation: %.4lf\n",
      target, approx_sqrt);

  double actual_sqrt = sqrt(target);
  printf("Actual square root of %.2lf: %.4lf\n", target, actual_sqrt);

  return 0;
}
