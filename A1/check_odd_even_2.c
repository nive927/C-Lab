#include<stdio.h>

int main()
{ 
  int no, flag;
  
  printf("Enter the number: ");
  scanf("%d", &no);

  flag=(no%2==0)? 0: 1;

  if(flag==0)
   printf("EVEN\n");

  else
   printf("ODD\n");

  return 0;
}
