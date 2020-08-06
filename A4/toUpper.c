#include<stdio.h>

char toUpper(char ch)
{
	if((ch>=65)&&(ch<=91))
		return ch;

	else
		return ch-32;

}

int main()
{
	char chr;
	
	printf("Enter character: ");
	scanf(" %c", &chr);

	printf("In Upper Case: %c\n", toUpper(chr) );
	
	return 0;
}
