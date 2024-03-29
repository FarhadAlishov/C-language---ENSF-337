/*
 *
 * lab2exe_E.c
 * ENSF 337 - Lab 2 - Execise E
 *
 *  Functions to read numbers with input error detection.
 *  Name: Farhad Alishov
 *
 */

#include <stdio.h>
#include <stdlib.h>

int read_int(void);
/*
 *  REQUIRES
 *      User has been prompted to type in an int.
 *  PROMISES
 *      If an int can be read from the standard input stream, that
 *      int is the return value.  If not, an error message is printed
 *      and exit is called with an argument of 1.
 */

double read_double(void);
/*
 *  REQUIRES
 *      User has been prompted to type in a double.
 *  PROMISES
 *      If a double can be read from the standard input stream, that
 *      double is the return value.  If not, an error message is printed
 *      and 'exit' is called with an argument of 1.
 */

int main(void)
{
  int the_int;
  double the_double;

  printf("Doing tests of read_int and read_double functions ...\n\n");

  printf("Please try to enter an int: ");
  the_int = read_int();

  printf("read_int succeeded.  It read a value of %d.\n", the_int);

  printf("Please try to enter a double: ");
  the_double = read_double();

  printf("read_double succeeded.  It read a value of %g.\n", the_double);

  return 0;
}

int read_int(void)
{
   int integer;
   int c, n;

   n = scanf("%d", &integer); //gets n, should be 1
   c = fgetc(stdin); //switches to next character

   if (n!=1 || (c!=EOF && c!=10)){
     printf("Your input is invalid\n");
     exit(1);
   }

   return integer;
}

double read_double(void)
{
  double doublenumber;
  int c, n;

  n = scanf("%lf", &doublenumber);
  c = fgetc(stdin);

  if (n!=1 || (c!=EOF && c!=10)){
    printf("Your input is invalid\n");
    exit(1);
  }

  return doublenumber;
}
