#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define size 45

struct Date
{
	int day;
	int month;
	int year;
};

struct Student
{
	char rollnum[size];
	char name[size];
	float marks[5];
	float totalMarks;
	int rank;
	struct Date dateofbirth;
	int age;
	char gender[size]; 
};

void input(struct Student *s, int N)
{
	printf("\nSTUDENT DETAILS ENTRY\n\n");

	for(int i=0; i<N; i++)
	{	
		float sum=0;

		printf("STUDENT %d\n", i+1);
	
		printf("Roll No: ");
		scanf("%s", (s+i)->rollnum);

		printf("Name: ");
		scanf(" %[^\n]%*c", (s+i)->name);

		printf("MARKS OBTAINED\n");
		for(int j=0; j<5; j++)
		{
			printf("Mark %d: ", j+1);
			scanf("%f", &(s+i)->marks[j]);
			
			sum+=(s+i)->marks[j];
		}

		(s+i)->totalMarks=sum;
		
		printf("DATE OF BIRTH in dd mm yyyy FORMAT:\n");
		scanf("%d %d %d", &(s+i)->dateofbirth.day, &(s+i)->dateofbirth.month, &(s+i)->dateofbirth.year);
		
		printf("Age: ");
		scanf("%d", &(s+i)->age);	
	
		printf("Gender: ");
		scanf(" %[^\n]%*c", (s+i)->gender);

		printf("\n");
	}	
}

void sort(struct Student *s, int N)
{
	struct Student small;
	
	for(int i=1; i<N; i++)
	{
		int j=i-1;
		small=s[i];

		while((small.totalMarks>((s+j)->totalMarks))&&(j>=0))
		{
			s[j+1]=s[j];
			j--;
		}
		
		s[j+1]=small;
	}	
}

void rank(struct Student *s, int N)
{
	sort(s, N);

	int count=0, pos=1;
	float next=(s+0)->totalMarks;

	for(int i=0; i<N; i++)
	{
		if(((s+i)->totalMarks)<next)	
		{
			next=(s+i)->totalMarks;
			pos+=count;
			count=0;
		}
		
		(s+i)->rank=pos;
		count++;
	}	
}

void output(struct Student *s, int N)
{
	printf("\nAVAILABLE STUDENT DETAILS\n\n");

	for(int i=0; i<N; i++)
	{	printf("STUDENT %d\n", i+1);
	
		printf("Roll No: %s\n", (s+i)->rollnum);
		
		printf("Name: %s\n", (s+i)->name);

		printf("MARKS OBTAINED\n");
		for(int j=0; j<5; j++)
			printf("Mark %d: %.2f\n", j+1, (s+i)->marks[j]);
			
		printf("Total Marks: %.2f\n", (s+i)->totalMarks);
		
		printf("Date of Birth: %d-%d-%d\n", (s+i)->dateofbirth.day, (s+i)->dateofbirth.month, (s+i)->dateofbirth.year);

		printf("Age: %d\n", (s+i)->age);

		printf("Gender: %s\n", (s+i)->gender);

		printf("Rank: %d\n", (s+i)->rank);

		printf("\n");
	}	
}

void marksheet(char roll[], struct Student *s, int N)
{
	for(int i=0; i<N; i++)
	{
		if(strcmp(roll, (s+i)->rollnum)==0)
		{
			int nwidth= strlen((s+i)->name), rwidth= strlen((s+i)->rollnum);

			char nm[]="NAME", rn[]="ROLL", r[]="RANK", to[]="TOTAL", ma[]="MARKS OBTAINED IN FIVE SUBJECTS";
	
			printf("\n%-*s%-*s%-7s%-9s%-9s\n\n", rwidth+6, rn, nwidth+4, nm, r, to, ma);

			
			printf("%-*s%-*s%-7d%-9.2f", rwidth+6, (s+i)->rollnum, nwidth+4, (s+i)->name, (s+i)->rank, (s+i)->totalMarks);

			for(int j=0; j<5; j++)
				printf("%-9.2f", (s+i)->marks[j]);

			printf("\n");

		}
	}
}

int main()
{
	struct Student *s;
	int N;
	char key[size], choice='C';

	printf("Enter the number of student records: ");
	scanf("%d", &N);

	s=(struct Student*)malloc(N*sizeof(struct Student));

	input(s, N);

	rank(s, N);

	output(s, N);

	while(choice=='C')
	{	printf("Enter rollnum of student for marksheet: ");
		scanf(" %[^\n]%*c", key);

		marksheet(key, s, N);

		printf("\nDo you want to continue getting marksheets?\nC: CONTINUE\nE: EXIT\n");
		scanf(" %c", &choice);
	}

	free(s);

	return 0;
}
