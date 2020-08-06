#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

double table (double (*pf)(double i, int m, double n),double a,int m,double n,int c);

double md1(double i, int m, double n);

double md2(double i, int m, double n);

double md3(double i, int m, double n);

int main()
{
	int i,j;
	double n,a,arr[50][6];
	int m_val[6] = {1,2,4,12,360,0};
	
	printf("Enter amount of each monthly payment: ");
	scanf("%lf",&a);
	
	printf("Enter number of years: ");
	scanf("%lf",&n);
	
	for(i=0;i<50;i++)
	{
		for(j=0;j<4;j++)
		{
			arr[i][j] = table(md1,a,m_val[j],n,i+1);
		}
	
		arr[i][4] = table(md2,a,m_val[4],n,i+1);
		arr[i][5] = table(md3,a,m_val[5],n,i+1);
	}
	
	printf(" R.O.I   Annual  Semiannual  Quarterly   Monthly     Daily    Continuous\n");
	
	for (i=0;i<50;i++)
	{
		printf(" %2d%% ",i+1);
		for(j=0;j<6;j++)
		{
			printf(" %9.2f ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;

}

double table (double (*pf)(double i, int m, double n),double a,int m,double n,int c)
{
	double i,f;
	i = 0.01*c;
	f = a*(*pf)(i,m,n);
	return f;
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
