


#include<stdio.h>

char* concatenate(char str1[], char str2[])
{
	int ws1, i, j;
	
	for(int i=0; str1[i]!='\0'; i++)
		ws1++;

	for(i=ws1, j=0; str1[j]!='\0'; i++, j++)
		str1[i]=str2[j];

	str1[++i]='\0';

	return str1;
}

int main()
{	
	char string1[30], string2[30];

	printf("Enter string1: ");
	scanf("%[^\n]%*c", string1);

	printf("Enter string2: ");
	scanf("%[^\n]%*c", string2);

	printf("The concatenated string is: ");
	printf("%s\n", concatenate(string1, string2));

	return 0;
}

