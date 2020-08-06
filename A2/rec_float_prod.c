#include<stdio.h>

float rec_prod(int n)
{    
   if(n!=0)
   { 
     float num;

     printf("Enter number: ");
     scanf("%f", &num);
     
     return num*rec_prod(n-1);
   }

   else
    return 1; 
}

int main()
{
  int limit;

  printf("Enter number of inputs: ");
  scanf("%d", &limit);

  printf("The product of inputs: %.4f\n", rec_prod(limit));
  
  return 0;

}
