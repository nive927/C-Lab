#include<stdio.h>

int main()
{ float num, sq_root;
  
  printf("Enter a number: ");
  scanf("%f", &num);
  
  sq_root=sqrt(num);

  printf("The square root of the number is %.2f\n", sq_root);

  return 0; 
}
