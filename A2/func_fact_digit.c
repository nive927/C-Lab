#include<stdio.h>

int factorial(int num)
{ 
  int fact=1;

  for(int i=2; i<=num; i++)
   fact*=i;
   
  return fact; 
}

int non_zero_digit(int num)
{
  int facto, digit;
  
  facto=factorial(num);
  
  while(facto!=0)
  { 
    digit=facto%10;

    if(digit!=0)
     break;
    
    facto/=10;   
  }

 return digit;   
  
}

int main()
{
  int no;

  printf("Enter number: ");
  scanf("%d", &no);

  printf("FACTORIAL: %d\n", factorial(no));
  printf("FIRST non-zero digit of the factorial: %d\n", non_zero_digit(no));
    
  return 0;
}
