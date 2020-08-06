#include<stdio.h>

int ReverseNum(int *num)
{ 
  int digit, reverse=0;

  while(*num!=0)
  { 
    digit=*num%10;
    reverse=(reverse*10)+digit;
    *num/=10;   
  }
   
  return reverse;

}

int main()
{
  int no;

  printf("Enter number: ");
  scanf("%d", &no);

  printf("Reversed number: %d\n", ReverseNum(&no));
  
  return 0;
}
