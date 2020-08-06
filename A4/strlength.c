#include<stdio.h>

int strlength(char s[])
{
	int size=0;

	for(int i=0; s[i]!='\0'; i++)
		size++;

	return size;
}

int main()
{
	char str[30];

	printf("Enter string: ");
	scanf("%[^\n]%*c", str);
	
	printf("The length of the string: %d\n", strlength(str));

	return 0;
}
