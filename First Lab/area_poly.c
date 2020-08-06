#include<stdio.h>
#define PI 3.14

void main()
{ 
  float length, breadth, base, height, radius, area_tri=0, area_rect=0, area_cir=0;
  
  printf("Enter the length of the rectangle: ");
  scanf("%f", &length);
  printf("Enter the breadth of the rectangle: ");
  scanf("%f", &breadth);
  
  area_rect= length*breadth;

  printf("The area of the rectangle is %.2f\n", area_rect);

  printf("Enter the base of the right-triangle: ");
  scanf("%f", &base);
  printf("Enter the height of the right-triangle: ");
  scanf("%f", &height);
  
  area_tri= 0.5*base*height;

  printf("The area of the triangle is %.2f\n", area_tri);

  printf("Enter the radius of the circle: ");
  scanf("%f", &radius);
    
  area_cir= PI*radius*radius;

  printf("The area of the circle is %.2f\n", area_cir);
  
  
}
