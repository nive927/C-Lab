#include <stdio.h> 
  
int main(int argc, char* argv[]) 
{	FILE *fptr1, *fptr2; 
	char c, choice;
	
	fptr1 = fopen(argv[1], "r");

	if (fptr1 == NULL)
	{
		printf("Cannot open file %s \n", argv[1]);
		return 0;
	}

	fptr2 = fopen(argv[2], "w");

	if (fptr2 == NULL)
	{
		printf("Cannot open file %s \n", argv[2]);
		return 0;
	}

	printf("File %s exists\n", argv[1]);
	printf("o: overwrite a:append\n\n");
	printf("Enter choice: ");
	scanf(" %c", &choice);

	if(choice=='o')
	{	
		c = fgetc(fptr1);
		while (c != EOF)
		{	
			fputc(c, fptr2);
			c = fgetc(fptr1);
		}	

		printf("\nContents of %s SUCCESSFULLY overwritten to %s\n", argv[1], argv[2]); 

		printf("New Contents of %s:\n", argv[1]);

		c = fgetc(fptr1);
		while (c != EOF)
		{	
			printf(" %c", c);
			c = fgetc(fptr1);
		}	


  
	}

	else if(choice=='a')
	{
		fclose(fptr2);
		fptr2 = fopen(argv[2], "a");

		c = fgetc(fptr1);
		while (c != EOF)
		{	
			fputc(c, fptr2);
			c = fgetc(fptr1);
		}	

		printf("\nContents of %s SUCCESSFULLY appended to %s\n", argv[1], argv[2]); 

	}

	fclose(fptr1);
	fclose(fptr2);

	return 0; 
}