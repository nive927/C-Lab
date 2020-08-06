#include<stdio.h>
#include<stdlib.h>

struct payslip
{
	float BP;
	float DA;
	float HRA;
	float CCA;
	float Insurance;
	float PF;
	float Gross_Pay;
	float Deductions;
	float Net_Pay;

};

void input(struct payslip *p)
{
	printf("Enter Basic Pay(BP) of the employee: ");
	scanf("%f", &p->BP);
}

void compute(struct payslip *p)
{
	p->DA=0.88*p->BP;
	p->HRA=0.08*p->BP;
	p->CCA=1000;
	p->Insurance=2000;	
	p->PF=0.10*p->BP;
	p->Gross_Pay=p->BP+p->DA+p->HRA+p->CCA;
	p->Deductions=p->Insurance+p->PF;
	p->Net_Pay=p->Gross_Pay-p->Deductions;
}

void output(struct payslip *p)
{

	printf("\n\n+--------------------------------------------------------+\n");
	printf("\t\tEMPLOYEE PAYSLIP\n");
	printf("+--------------------------------------------------------+\n\n");

	printf(" Basic Pay                    : %.2f\n", p->BP);
	printf(" Dearness Allowance           : %.2f\n", p->DA);
	printf(" House Rent Allowance         : %.2f\n", p->HRA);
	printf(" City Compensatory Allowance  : %.2f\n", p->CCA);
	printf(" Insurance                    : %.2f\n", p->Insurance);
	printf(" Provident Fund               : %.2f\n", p->PF);
	printf(" Gross Pay                    : %.2f\n", p->Gross_Pay);
	printf(" Deductions                   : %.2f\n", p->Deductions);
	printf(" Net Pay                      : %.2f\n", p->Net_Pay);
	
}

int main()
{
	struct payslip *p;

	p=(struct payslip*)malloc(sizeof(struct payslip));

	input(p);
	
	compute(p);

	output(p);
	
	return 0;
}
