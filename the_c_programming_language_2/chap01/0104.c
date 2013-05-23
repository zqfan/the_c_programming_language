/* Write a program to print the corresponding Celsius to Fahrenheit
   table. */
#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300; floating-point version */
main() {
  float fahr, celsius;
  float lower, upper, step;
  lower = -200;     /* lower limit of temperatuire scale */
  upper = 300;   /* upper limit */
  step = 20;     /* step size */
  celsius = lower;
  printf("%6s %6s\n", "Cels", "Fahr");
  while (fahr <= upper) {
    fahr = celsius * 9.0 / 5.0 + 32.0;
    printf("%6.0f %6.1f\n", celsius, fahr);
    celsius += step;
  }
}
