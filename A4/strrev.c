


#include<stdio.h>
#include<string.h>

void strrev(char str[])
{
	int ws=strlen(str);
	

	if(ws%2==1)
	{	
		for(int i=0, j=ws-1; i<=ws/2; i++, j--)
		{
			int t=str[i];
			str[i]=str[j];
			str[j]=t;
		}
	}

	else
	{	
		for(int i=0, j=ws-1; i<=ws/2; i++, j--)
		{
			int t=str[i];
			str[i]=str[j];
			str[j]=t;
		}
	}

}

int main()
{	
	char string[30];

	printf("Enter ORIGINAL string: ");
	scanf("%[^\n]%*c", string);

	strrev(string);

	printf("REVERSED string: ");
	printf("%s\n", string);

	return 0;
}

