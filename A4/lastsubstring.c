#include<stdio.h>
#include<string.h>

int last_substr(char src[], char sub[])
{
	int n1=strlen(src);
	int n2=strlen(sub);
	char check[45];
	
	for(int i=n1-1; i>=0; i--)
	{
			

		if(src[i]==sub[n2-1])
		{
			int k=0, flag=0;	
			
			for(int j=i; j>i-n2; j--)
				check[k++]=src[j];
			check[k]='\0';

			for(int j=0, l=n2-1; j<n2; j++, l--)
				if(check[l]!=sub[j])
					flag=1;
			
			if(flag==0)
				return i-n2+2;
		}
	

	}
	
	return -1;	

}
int main()
{	
	char source[45], substr[45], flag;

	printf("Enter line: ");
	scanf("%[^\n]%*c", source);

	printf("Enter sub-string: ");
	scanf("%[^\n]%*c", substr);

	flag=last_substr(source, substr);

	if(flag!=-1)
		printf("FOUND at position %d\n", flag);

	else
		printf("NOT FOUND\n");

	return 0;
}
