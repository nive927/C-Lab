#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char *lines[50];
	char line[100];
	int count=0;
	int i=0,j;
	

	do
	{
		printf("Enter line: ");
		scanf(" %[^\n]", line);
		
		lines[i]=(char*)malloc(sizeof(char)*strlen(line)+1);
		strcpy(lines[i], line);

		count++;

	}while(strcmp(lines[i++],"END"));
	
	printf("\nList of TOKENS: ");

	for(int i=0;strcmp(lines[i],"END");i++)
	{
		j=0;
		printf("\n");

		while(lines[i][j]!='\0')
		{
			if(lines[i][j]!=' ')
				printf("%c",lines[i][j]);
			
			else
			{
				printf("\n");
				count++;
			}
			
			j++;
		}
	}

	printf("\nTOTAL number of TOKENS: %d\n",count-1);

}