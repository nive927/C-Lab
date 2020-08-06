#include<stdio.h>

int main()
{ int N, sum=0;

  printf("Enter positive number less than 100\n");
  printf("Enter number: ");
  
  while(scanf("%d", &N))
  { 
    if(!((N>=0)&&(N<100)))
    { printf("INVALID INPUT\n");
      break;
    }

    sum+=N;
    printf("Enter number: ");
    
  }    

  printf("The sum of the above numbers is: %d\n", sum);
  
  return 0;
}
