#include<stdio.h>

int main()
{ 
  int no, flag=0;
  
  printf("Enter the number: ");
  scanf("%d", &no);
   
  while(no!=0)
  { if(no%1000==555)
     { printf("The number has three consecutive 5's");
       flag=1;
       break;
     }

    no/=10;
  }

  if(flag==0)
   printf("The number doesn't have three consecutive 5's\n");
 
  return 0;
 
}
