#include<stdio.h>

int main()
{ 

  int N, sp;

  sp=1;

  printf("Enter the size of egg-timer: ");
  scanf("%d", &N);

  if ((N>3) && (N<10))
  
  { for(int i=N; i>=1; i--)
   
     { for(int j=1; j<sp; j++)
        printf(" ");
   
       sp++;
   
       for(int k=i; k>=1; k--)
        printf("*_");
    
       printf("\b \n");
     }
    
    sp=N-1;
    
    for(int i=2; i<=N; i++)

     { for(int j=1; j<sp; j++)
        printf(" ");
      
       sp--;

       for(int k=1; k<=i; k++)
        printf("*_");

       printf("\b \n");
     }
  }

  else
   printf("INVALID INPUT\n");

  return 0;
}  
