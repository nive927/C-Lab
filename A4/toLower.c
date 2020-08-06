#include<stdio.h>

char toLower(char ch)
{
	if((ch>=97)&&(ch<=123))
		return ch;

	else
		return ch+32;

}

int main()
{
	char chr;
	
	printf("Enter character: ");
	scanf(" %c", &chr);

	printf("In Lower Case: %c\n", toLower(chr));
	
	return 0;
	
}
