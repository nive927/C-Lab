#include<stdio.h>
#include<stdlib.h>

#define N 20

void input(int (*T)[N], int r, int c)
{
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			printf("Enter element: ");
			scanf("%d", &(*(*(T+i)+j)));
		}
	}
}

void greater(int (*A)[N], int (*B)[N], int (*C)[N], int r, int c)
{
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			*(*(C+i)+j)= *(*(A+i)+j)>*(*(B+i)+j)?*(*(A+i)+j):*(*(B+i)+j);
	

}

void output(int (*T)[N], int r, int c)
{
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			printf("Element: %d\n", *(*(T+i)+j));
}

int main()
{
	int r, c;
	int (*A)[N], (*B)[N], (*C)[N];

	printf("Enter row count: ");
	scanf("%d", &r);
	printf("Enter column count: ");
	scanf("%d", &c);

	A=(int**)malloc(r*sizeof(int*));
	B=(int**)malloc(r*sizeof(int*));
	C=(int**)malloc(r*sizeof(int*));
	
	printf("\n\nTABLE 1:\n");
	input(A, r, c);

	printf("\n\nTABLE 2:\n");
	input(B, r, c);

	printf("\n\nGREATER OF THE CORRESPONDING TABLE ELEMENTS:\n");
	greater(A, B, C, r, c);
	output(C, r, c);

	return 0;
	
} 

