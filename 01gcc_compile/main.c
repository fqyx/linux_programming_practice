#include <stdio.h>
#include "reciprocal.hpp"
int main(int argc, char *argv[])
{
   printf("This is a test program for C/C++!\n");
   int i;
   i = atoi(argv[1]);
   printf("The reciprocal of %d is %g\n",i, reciprocal(i));
   return 0;
}
