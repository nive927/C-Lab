



#include<stdio.h>

int chrpos(char str1[], char ch)
{
	int pos=-1;
	
	for(int i=0; str1[i]!='\0'; i++)
		if(str1[i]==ch)
		{	pos=i+1;
			break;
		}

	return pos;
		
}

int main()
{	
	char string1[30], chr;
	
	printf("Enter string: ");
	scanf("%[^\n]%*c", string1);

	printf("Enter character: ");
	scanf(" %c", &chr);

	printf("Position of the first occurence of the characer: %d\n", chrpos(string1, chr));
	
	return 0;
}

