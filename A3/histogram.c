#include<stdio.h>

void histogram(int a[], int ws)
{
	int hist[10], n, max, count;	

	for(int i=0; i<10; i++)
		hist[i]=0;
	
	for(int i=0; i<ws; i++)
	{	n=a[i];
		hist[n]++;
	}

	max=hist[0];
	for(int i=1; i<10; i++)
		if(hist[i]>max)
			max=hist[i];
	
	count=max;
	for(int i=0; i<max; i++)
	{	
		for(int j=0; j<10; j++)
		{	if(hist[j]>=count)
				printf("*");
			
			else
				printf(" ");
		}
		
		count--;
		printf("\n");
	}

	printf("0123456789\n");

}

int main()
{
	int arr[15], size;

	printf("Enter the size: ");
	scanf("%d", &size);
	printf("\n");

	for(int i=0; i<size; i++)
	{	printf("Enter digit: ");
		scanf("%d", &arr[i]);
	}
	printf("\n");

	histogram(arr, size);

	return 0;

}