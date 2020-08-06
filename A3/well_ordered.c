#include<stdio.h>

int well_ordered(int num)
{
	int a[3], count=0;
	
	for(int i=0; i<3; i++)
	{	
		a[i]=num%10;
		num/=10;
	}
	
	for(int i=0; i<2; i++)
		if(a[i]<=a[i+1])
			count=1;
	
	if(count==0)
		return 1;

	else
		return 0;

}

int main()
{
	int check=0, flag=0;

	printf("The list of all well-ordered three digit numbers\n\n");

	for(int i=100; i<1000; i++)
	{	
		check=well_ordered(i);
		
		if(check==1)
		{	printf("%d\n", i);
			flag++;
		}
		
		check=0;

	}

printf("\nThe total number of well-ordered three digit numbers are: %d\n", flag);

	return 0;
}