#include<stdio.h>

struct check
{
	char id[10];
	char name[45];
};

int main()
{
	struct check tester;

	printf("ENTRY 1:\n\n");

	printf("ID: ");
	scanf(" %[^\n]%*c", tester.id);

	printf("Name: ");
	scanf(" %[^\n]%*c", tester.name);

	printf("\nID: %s\n", tester.id);
	printf("Name: %s\n", tester.name);

	printf("ENTRY 1:\n\n");

	printf("ID: ");
	scanf(" %[^\n]%*c", tester.id);

	printf("Name: ");
	scanf(" %[^\n]%*c", tester.name);

	printf("\nID: %s\n", tester.id);
	printf("Name: %s\n", tester.name);

	return 0;
}