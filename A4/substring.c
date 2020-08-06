#include<stdio.h>
#include<string.h>

char* change_str(char source[], char substr[], char replace[])
{
	static char new[60];
	static int i=0, h;
	
	for(h=0; source[h]!='\0'; h++)
	{	
		
		if(source[h]!=substr[0])
			new[i++]=source[h]; 
		
		else
		{
			int k=0, flag=0;
			char check[45];			

			for(int j=h; j<h+strlen(substr); j++)
				check[k++]=source[j];
			check[k]='\0';

			for(int l=0; l<strlen(substr); l++)
				if(check[l]!=substr[l])
					flag=1;
			

			if(flag==0)
			{	int m=0;
				
				for(int n=i; n<i+strlen(replace); n++)
					new[n]=replace[m++];
				
				i+=strlen(replace);
				h+=strlen(substr)-1;
				
			}

			if(flag==1)
				 new[i++]=source[h]; 				
		}
	}
	
	new[i]='\0';
	return new;

}

int main()
{	
	char source[60], substr[45], replace[45];

	printf("Enter line: ");
	scanf("%[^\n]%*c", source);

	printf("Enter sub-string: ");
	scanf("%[^\n]%*c", substr);

	printf("Enter substitute: ");
	scanf("%[^\n]%*c", replace);

	printf("The new line is:");
	printf(" %s\n", change_str(source, substr, replace));

	return 0;
}

