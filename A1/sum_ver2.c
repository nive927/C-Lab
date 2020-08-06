#include<stdio.h>

int main()
{ int N, sum=0;

  printf("Enter number: ");
  scanf("%d", &N);

  do
  { sum+=N;
    printf("Enter number: ");
    scanf("%d", &N);
  }while(N!=-999);
    

  printf("The sum of the above numbers is: %d\n", sum);
  
  return 0;
}
