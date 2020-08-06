#include<stdio.h>

int CheckOddEven(int num)
{ 
   int flag;

   flag=(num%2==0)?0:1;
   
   return flag; 
}

int main()
{
  int no, N, sum_odd=0, sum_even=0;

  printf("Enter number of inputs: ");
  scanf("%d", &N);

  for(int i=1; i<=N; i++)
  {
    printf("Enter number: ");
    scanf("%d", &no);

    if((CheckOddEven(no))==0)
     sum_even+=no; 

    else
     sum_odd+=no;
  } 

  printf("The sum of odd number inputs: %d\n", sum_odd);
  printf("The sum of even number inputs: %d\n", sum_even);
  
  return 0;

}
