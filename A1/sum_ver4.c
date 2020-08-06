#include<stdio.h>

int main()
{ int N, sum=0;

  printf("Enter positive number less than 100\n");
  printf("Enter number: ");
  scanf("%d", &N);

  while((N>=0)&&(N<100))
  { sum+=N;
    printf("Enter number: ");
    scanf("%d", &N);
  }
    

  printf("The sum of the above numbers is: %d\n", sum);
  
  return 0;
}
