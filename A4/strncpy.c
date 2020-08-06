


#include<stdio.h>

void copy(char dest[], char src[], int n)
{
	int i;
	
	for(i=0; i<n; i++)
		dest[i]=src[i];

	dest[n]='\0';
}

int main()
{	
	char string1[30], string2[30];
	int limit;

	printf("Enter ORIGINAL string: ");
	scanf("%[^\n]%*c", string1);

	printf("Enter limit: ");
	scanf("%d", &limit);

	copy(string2, string1, limit);

	printf("COPIED String: ");
	printf("%s\n", string2);

	return 0;
}

