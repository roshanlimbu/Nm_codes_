#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 5

float f(float x) { return log(x); }

int main() {
  float x[N] = {1, 2, 3, 4, 5};
  float y[N];
  float value, result = 0;

  printf("Enter the value for interpolation: ");
  scanf("%f", &value);

  for (int i = 0; i < N; i++) {
    y[i] = f(x[i]);
  }

  for (int i = 0; i < N; i++) {
    float term = y[i];
    for (int j = 0; j < N; j++) {
      if (j != i) {
        if (x[i] - x[j] != 0) {
          term *= (value - x[j]) / (x[i] - x[j]);
        } else {
          continue; // Skip division by zero
        }
      }
    }
    result += term;
  }

  printf("Interpolated value: %f if %f\n", value, result);

  return 0;
}
