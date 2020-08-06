#include<stdio.h>

int main()
{ float BP, DA, HRA, CCA=1000.0, insurance=2000.0, PF, gross, deduct, net;
  char name[15], empid[10];

  printf("Enter the details of the employee");
  printf("\nName: ");  
  scanf("%s", name);

  printf("Empoyee ID: ");  
  scanf("%s", empid);

  printf("Basic Pay: ");  
  scanf("%f", &BP);

  DA=0.88*BP;
  HRA=0.08*BP;
  PF=0.12*BP;
  gross=BP+DA+HRA+CCA;
  deduct=insurance+PF;
  net=gross-deduct;

  printf("\n\tPAYSLIP for the employee\n");
  printf("\n\tName: %8s\n\tEmpid: %11s\n\tBP: %16.2f\n\tDA: %15.2f\n\tHRA: %13.2f\n\tCCA: %13.2f\n\tInsurance: %.2f\n\tGross Pay: %.2f\n\tDeduction: %.2f\n\n\t\tNet Pay: %.2f\n\n", name, empid, BP, DA, HRA, CCA, insurance, gross, deduct, net);

  return 0;
}
