#include<stdio.h>
#include<math.h>

const double tolerance = 0.001;
double compute(double x) {
  return (6*pow(x, 3.0) + exp(2*x) - 1) / 5;
}
int main() {
  double x = 1.0, root = 1.5, iter = 5.0, i = 1.0;
  while (true) {
    x = compute(x);   
    if ((fabs(x - root)) < tolerance) {
      break;
    } 
    printf( "Current value: ",x );
    i++;
    root = x;
    if (i > iter) {
      printf("Method failed\nFunction diverged\n");
      break;
    }
  }

  return 0;
}