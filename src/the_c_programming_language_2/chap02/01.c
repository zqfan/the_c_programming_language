/* Write a program to determine the ranges of char, short, int, and
   long variables, both signed and unsigned, by printing appropriate
   values from standard headers and by direct computation. Harder if
   you compute them: determine the ranges of the various
   floating-point types.
*/
#include<stdio.h>
#include<limits.h>
#include<float.h>
#include<math.h>

/* /usr/include/limits.h */
/* /usr/lib/gcc/i686-linux-gnu/4.6/include/float.h */
int main() {
  /* range of char */
  printf("compute singed char min: %d, max: %d\n",
         -(int)pow(2, sizeof(char)*7),
         (int)pow(2, sizeof(char)*7) - 1);
  printf("signed char min: %d, max: %d\n", SCHAR_MIN, SCHAR_MAX);
  printf("unsigned char min: %d, max: %d\n", 0, UCHAR_MAX);

  /* range of short */
  printf("short min: %d, max: %d\n", SHRT_MIN, SHRT_MAX);
  printf("unsigned short min: %d, max: %d\n", 0, USHRT_MAX);

  /* range of int */
  printf("int min: %d, max: %d\n", INT_MIN, INT_MAX);
  printf("unsigned int min: %u, max: %u\n", 0, UINT_MAX);

  /* range of long */
  printf("long int min: %ld, max: %ld\n", LONG_MIN, LONG_MAX);
  printf("unsigned long int min: %lu, max: %lu\n", 0ul, ULONG_MAX);

  /* range of float
     here you must use %e for print format, or the min will be 0(wrong
     answer) and the max will print very long(not pretty)
  */
  printf("float min: %e, max: %e\n", FLT_MIN, FLT_MAX);
  printf("doule float min: %le, max: %le\n", DBL_MIN, DBL_MAX);
  printf("long double float min: %Le, max: %Le\n", LDBL_MIN, LDBL_MAX);

  return 0;
}
