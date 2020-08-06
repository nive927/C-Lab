#include<stdio.h>

int main()
{ int N, sum=0, no;

  printf("Enter limit: ");
  scanf("%d", &N);

  for(int i=1; i<=N; i++)
  { printf("Enter number: ");
    scanf("%d", &no);
    
    sum+=no;
  }

  printf("The sum of the above numbers is: %d\n", sum);
  
  return 0;
}
