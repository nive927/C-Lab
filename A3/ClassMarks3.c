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

float stu_deviate(float scores[][10], int wc, int wr, int i)
{
	float result;

	result=stu_avg(scores[i], wc)-class_avg(scores, wc, wr);

	if(result>0)
		return result;

	else
		return -(result);
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
		
	float class_mean=class_avg(marks, n, N);
	printf("\nOverall CLASS AVERAGE: %.2f\n", class_mean);

	char nm[]="NAME", av[]="AVERAGE", dev[]="DEVIATION", ma[]="MARKS OBTAINED IN SUBJECTS";
	printf("\n%-*s%-11s%-13s%-18s\n\n", width+4, nm, av, dev, ma);

	
	for(int i=0; i<N; i++)
	{
		printf("%-*s%-11.2f%-13.2f", width+4, name[i], stu_avg(marks[i], n), stu_deviate(marks, n, N, i));
		
		for(int j=0; j<n; j++)
			printf("%-11.2f", marks[i][j]);

		printf("\n");
			
			// printf("\nAverage: %.2f\n\n", stu_avg(marks[i], n));

	}
	
	return 0;  
}