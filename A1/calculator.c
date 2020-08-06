#include<stdio.h>

int main()
{ 
  int choice;
  float no1, no2, result;
  
  printf("1: ADDITION\n2: SUBTRACTION\n3: MULTIPLICATION\n4: DIVISION\n5: EXPONENT\n");
  printf("Enter the choice: ");
  scanf("%d", &choice);
 
  printf("Enter number 1: ");
  scanf("%f", &no1);

  printf("Enter number 2: ");
  scanf("%f", &no2);

  switch(choice)
  { 
    case 1: result=no1+no2;
            break;

    case 2: result=no1-no2;
            break;

    case 3: result=no1*no2;
            break;  

    case 4: result=no1/no2;
            break;

    case 5: result=no1*no1;
            break;

    default: printf("INVALID CHOICE INPUT\n");

  }

  printf("The result of the operation is: %.2f\n", result);

  return 0;
}
