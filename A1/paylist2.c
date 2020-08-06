#include<stdio.h>

int main()
{  
  float BP, DA, HRA, CCA, insurance=1000, PF, GP, DEDUCT, NP;
  char type_HRA, type_CCA;
  printf("Enter Basic Pay of employee: ");
  scanf("%f", &BP);

  DA=0.88*BP;

  printf("M: Metro\nC: Corporation\nT: Taluk\n");
  printf("Enter city type: ");
  scanf(" %c", &type_HRA);

  if(type_HRA=='M')
   HRA=0.1*BP;

  else if(type_HRA=='C')
   HRA=0.08*BP;

  else if(type_HRA=='T')
   HRA=0.05*BP;
  
  printf("W: Worker\nE: Engineer\nM: Manager\n");
  printf("Enter designation: ");
  scanf(" %c", &type_CCA);

  if(type_CCA=='W')
   CCA=1000;

  else if(type_CCA=='E')
   CCA=2000;

  else if(type_CCA=='M')
   CCA=5000;

  PF=0.1*BP;
  GP=BP+DA+HRA+CCA;
  DEDUCT=insurance+PF;
  NP=GP-DEDUCT;

  printf("The Net Pay of the employee: %.2f\n", NP);  
   
  return 0;
}
