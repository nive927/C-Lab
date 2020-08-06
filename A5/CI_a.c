#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void table (double (*pf)(double i, int m, double n),double a,int m,double n);

double md1(double i, int m, double n); 

double md2(double i, int m, double n);

double md3(double i, int m, double n);

int main()
{
	int i;
	double n,a;
	int m_val[6] = {1,2,4,12,360,0};
	
	printf("Enter amount of each monthly payment: ");
	scanf("%lf",&a);
	
	printf("Enter number of years: ");
	scanf("%lf",&n);
	
	printf("Rate of int.    5%%       6%%       7%%        8%%       9%%      10%%      11%%      12%%      13%%      14%%      15%%\n");
	
	for(i=0;i<4;i++)
	{
		if(i==0)
			printf("Annual       ");
		else if(i==1)
			printf("Semiannual   ");
		else if(i==2)
			printf("Quarterly    ");
		else
			printf("Monthly      ");
		table(md1,a,m_val[i],n);
		printf("\n");
	}
	
	printf("Daily        ");
	
	table(md2,a,m_val[4],n);
	
	printf("\n");
	
	printf("Continuous   ");
	
	table(md3,a,m_val[5],n);

	printf("\n");

	return 0;
}
//function that accepts a pointer to another function as argument
void table (double (*pf)(double i, int m, double n),double a,int m,double n)
{
	int c;
	double i,f;
	for(c=5;c<=15;c++)
	{
		i = 0.01*c;
		f = a*(*pf)(i,m,n);
		printf(" %.2f ",f);
	}
}

double md1(double i, int m, double n)
{
	double fact,ratio;
	fact = 1 + i/m;
	ratio = 12*(pow(fact,m*n)-1)/i;
	return ratio;
}


double md2(double i, int m, double n)
{
	double fact,ratio;
	fact = 1 + i/m;
	ratio = (pow(fact,m*n)-1)/(pow(fact,m/12)-1);
	return ratio;
}

double md3(double i, int m, double n)
{
	double ratio;
	ratio = (exp(i*n)-1)/(exp(i/12)-1);
	return ratio;
}