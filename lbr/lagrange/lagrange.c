#include <math.h>
#include <stdio.h>
#define N 5
float f(float x) { return log(x); }
int main() {
  float x[N] = {1, 2, 3, 4, 5};
  float y[N];
  float value, result = 0;
  printf("Enter the value fo interplation");
  scanf("%f", &value);
  for (int i = 0; i < N; i++) {
    y[i] = f(x[i]);
  }
  for (int i = 0; i < N; i++) {
    float term = y[i];
    for (int j = 0; j < N; j++) {
      if (j != i) {
        term *= (value - x[j]) / (x[i] - x[j]);
      }
    }
    result += term;
  }
  printf("Interpolated value: %f if %f", value, result);
  return 0;
}
