#include <math.h>
#include <stdio.h>

float f(float x) {
  return x * x * x + x * x - 1;
}

float g(float x) {
  return 1 / sqrt(1 + x);
}

int main() {
  float x0, x1;
  float e = 0.0001;
  int itr = 1;
  
  printf("Enter initial guess:\n");
  scanf("%f", &x0);

  do {
    x1 = g(x0);
    printf("Iteration %d, root x%d = %f\n", itr, itr, x1);
    itr++;
    x0 = x1;
  } while (fabs(x1 - x0) > e);

  printf("\nFinal root = %f\n", x1);
  return 0;
}
