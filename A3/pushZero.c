#include<stdio.h>

void pushZerosToEnd(int arr[], int n) 
{	
	int count = 0;   
  	
	for (int i = 0; i < n; i++)
		if (arr[i] != 0) 
			arr[count++] = arr[i]; 
 
 	while (count < n) 
 		arr[count++] = 0; 
} 
int main()
{
	int a[20], ws;

	printf("Enter the size: ");
	scanf("%d", &ws);
	printf("\n");

	for(int i=0; i<ws; i++)
	{	printf("Enter number: ");
		scanf("%d", &a[i]);
	}
	printf("\n");

	printf("ORIGINAL ARRAY: ");
	printf("{");
	for(int i=0; i<ws; i++)
		printf("%d, ", a[i]);
	printf("\b\b}\n");

	pushZerosToEnd(a, ws);
	
	printf("NEW ARRAY: ");
	printf("{");
	for(int i=0; i<ws; i++)
		printf("%d, ", a[i]);
	printf("\b\b}\n");

	return 0;
}

