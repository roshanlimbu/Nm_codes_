#include <math.h>
#include <stdio.h>

float f(float x) {
  float z;
  z = sqrt(1 - x * x);
  return z;
}

int main() {
  float x0, xn, x1, k, h, term, v;
  printf("Enter the value of lower limit:\n");
  scanf("%f", &x0);
  printf("Enter the value of upper limit:\n");
  scanf("%f", &xn);
  printf("Enter the value of k (must be multiple of 3):\n");
  scanf("%f", &k);
  if (fmod(k, 3) != 0) {
    printf("k must be a multiple of 3.\n");
    return 1;
  }
  term = f(x0) + f(xn);
  h = (xn - x0) / k;
  for (int i = 1; i < k; i++) {
    if (i % 3 == 0) {
      term = term + 2 * f(x0 + i * h);
    } else {
      term = term + 3 * f(x0 + i * h);
    }
  }
  v = 3 * h / 8 * (term);
  printf("Root = %f\n", v);
  return 0;
}
