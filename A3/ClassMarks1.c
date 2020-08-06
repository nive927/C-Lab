#include<stdio.h>
#include<string.h>

float stu_avg(float scores[], int ws)
{
	float sum=0;
	
	for(int i=0; i<ws; i++)
		sum+=scores[i];

	return (sum/ws);
}

float class_avg(float scores[][10], int wc, int wr)
{
	float sum=0, avg=0;
	
	for(int i=0; i<wr; i++)
		{	
			avg=stu_avg(scores[i], wc);
			sum+=avg;
		}

	return (sum/wr);
}



int main()
{	
	int N, n;
	char name[15][25];
	float marks[15][10];

	printf("Enter the number of exam scores per student: ");
	scanf("%d", &n);

	printf("Enter the total number of students: ");
	scanf("%d", &N);

	for(int i=0; i<N; i++)
	{
		printf("\nStudent %d:\n\n", i+1);
		printf("NAME: ");
		scanf("%s", name[i]);
		
		for(int j=0; j<n; j++)
		{	printf("Mark %d: ", j+1);
			scanf("%f", &marks[i][j]);
		}
	}

	int width= strlen(name[0]);
	for(int i=1; i<N; i++)
		if(strlen(name[i])>width)
			width=strlen(name[i]);
		

	printf("\nOverall CLASS AVERAGE: %.2f\n", class_avg(marks, n, N) );

	char nm[]="NAME", av[]="AVERAGE" c, ma[]="MARKS OBTAINED IN SUBJECTS";
	printf("\n%-*s%-11s%-18s\n\n", width+4, nm, av, ma);

	
	for(int i=0; i<N; i++)
	{
		printf("%-*s%-11.2f", width+4, name[i], stu_avg(marks[i], n));
		
		for(int j=0; j<n; j++)
			printf("%-11.2f", marks[i][j]);

		printf("\n");
			
			// printf("\nAverage: %.2f\n\n", stu_avg(marks[i], n));

	}
	
	return 0;  
}