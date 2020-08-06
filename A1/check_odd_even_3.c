#include<stdio.h>

int main()
{ 
  int no;
  
  printf("Enter the number: ");
  scanf("%d", &no);

  (((no%2) && (printf("ODD");)) || (printf("EVEN");))

  return 0;
}
