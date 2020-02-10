/*  Example: C program to find area of a circle */

#include <stdio.h>
#define PI 3.14159

int main()
{
  float r, a, c;
  printf("Enter radius (in mm):\n");
  scanf("%f", &r);
  
    while( r!= 0){
  a = PI *(( r * r) / 645.16);
  c = PI * 2 * (r/25.4);

  printf("Circle's area is %3.2f (sq in).\n", a);
  printf("Its circumference is %3.2f (in).\n", c);
        
  printf("Enter radius (in mm):\n");
  scanf("%f", &r);
  }
}
