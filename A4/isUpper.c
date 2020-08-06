#include<stdio.h>

int isUpper(char ch)
{
	if((ch>=65)&&(ch<=91))
		return 1;

	else
		return 0;
}

int main()
{
	char chr;
	
	printf("Enter character: ");
	scanf(" %c", &chr);

	printf("Is the character in Upper Case?: ");
	isUpper(chr)?printf("YES\n"):printf("NO\n");

	return 0;
}
