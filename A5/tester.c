#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int word_count(const char *str, const char *word)
{
	char *check=(char*)malloc(sizeof(char)*30);
	int count=0;
	
	while(*str!='\0')
	{
		int flag=-1;
		
		if(*str!=' ')
		{
			*check=*str;
			check++;
			str++;
		}

		else
		{    	check='\0';
			
			printf("check: %s\n", check);

			flag=strcmp(check, word);

			if(flag==0)
				count++;

			else
			{
				check=NULL;
				str++;
			}
		}

	}

	return count;

}

int main()
{	
	char source[60], substr[45];

	printf("Enter line: ");
	scanf("%[^\n]%*c", source);

	printf("Enter word: ");
	scanf("%[^\n]%*c", substr);

	printf("The frequency of occurence of the word in the line is: %d\n", word_count(source, substr));
	
	return 0;
}
