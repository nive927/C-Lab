#include<stdio.h>
#include<stdlib.h>

#define M 20

void input(int *T[], int r, int c)
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

void add(int *A[], int *B[], int *C[], int r, int c)
{
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			*(*(C+i)+j)= *(*(A+i)+j)+*(*(B+i)+j);
	

}

void output(int *T[], int r, int c)
{
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			printf("Element: %d\n", *(*(T+i)+j));
}

int main()
{
	int r, c;
	int *A[M], *B[M], *C[M];

	printf("Enter row count: ");
	scanf("%d", &r);
	printf("Enter column count: ");
	scanf("%d", &c);

	for(int i=0; i<r; i++)
	{
		A[i]=(int*)malloc(c*sizeof(int));
		B[i]=(int*)malloc(c*sizeof(int));
		C[i]=(int*)malloc(c*sizeof(int));
	}

	printf("\n\nTABLE 1:\n");
	input(A, r, c);

	printf("\n\nTABLE 2:\n");
	input(B, r, c);

	printf("\n\nSUM OF THE CORRESPONDING TABLE ELEMENTS:\n");
	add(A, B, C, r, c);
	output(C, r, c);

	return 0;
	
} 
