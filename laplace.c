// laplace method
#include <math.h>
#include <stdio.h>

int main() {
  float u1, u2 = 0, u3 = 0, u4 = 0, err, ou1 = 0;
  int i;
  printf("\nu1         \tu2           \tu3           \tu4          \n");
  do {
    u1 = (u2 + u3 + 125) / 4;
    u2 = (u1 + u4 + 150) / 4;
    u3 = (u1 + u4 + 375) / 4;
    u4 = (u2 + u3 + 400) / 4;
    printf("%f\t%f\t%f\t%f\n", u1, u2, u3, u4);
    err = fabs((u1 - ou1) / u1);
    ou1 = u1;

  } while (err >= 0.0001);
  return 0;
}
