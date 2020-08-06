#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 45

int search(char *ptr[N],char search[N])
{
	int i=0,j,freq=0,k,count=0;;

	for(i=0;strcmp(ptr[i],"END");i++)

	{
		j=0,k=0;
		
		while(ptr[i][j]!='\0')
		{
			while(ptr[i][j]==search[k])
			{
				j++,k++;

				count+=1;
            
				if(count == strlen(search))
				{	freq+=1;
					count=0;
					k=0;
				}
			}
			
			j++;
            }

    }

	return freq;
}


int main()
{
	char *ptr[N];
	char line[N];

	char word[N];
	int i=0,freq;
    
	printf("Enter search word: ");
	scanf(" %[^\n]",word);

	do
	{
		printf("Enter line: ");
		scanf(" %[^\n]",line);

		ptr[i]=(char *) malloc(sizeof(char)*strlen(line)+1);
		strcpy(ptr[i],line);
	
	}while(strcmp(ptr[i++],"END"));
	
	freq=search(ptr,word);

	printf("\nFrequency = %d\n",freq);
}

