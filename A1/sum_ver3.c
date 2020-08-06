#include<stdio.h>

int main()
{ int N, sum=0;
  char ch='a';

  while(ch!='s')
  { printf("Enter number: ");
    scanf("%d", &N);

    sum+=N;

    printf("a: INPUT s: EXIT\n");
    printf("Enter the choice: ");
    scanf(" %c", &ch);

  }
    

  printf("The sum of the above numbers is: %d\n", sum);
  
  return 0;
}
