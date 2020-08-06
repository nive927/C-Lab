#include<stdio.h>

int print(int N)
{
  if(N!=1)
   { 
     printf("%d", N-1);
          
     return print(N-1);
   }

   else
    return 0; 
}

int main()
{
  int n;

  printf("Enter number: ");
  scanf("%d", &n);

  printf("%d\n", print(n));

  return 0;

}
