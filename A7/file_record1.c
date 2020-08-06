#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define size 45
FILE *fptr;

struct location
{
	char street[size];
	char city[size];
	char pincode[size];
};

struct contact
{
	char name[size];
	struct location address;
	char telephone[size];

}record;

void write_record()
{
	system("clear");

	char exit;

	fptr=fopen("contacts.txt", "a");

	//STORING DETAILS ONTO STRUCTURE TEMPORARILY
	
	printf("+----------------------------+\n");
	printf("\tNEW CONTACT ENTRY\n");
	printf("+----------------------------+\n\n");
		
	printf("Name: ");
	scanf(" %[^\n]%*c", record.name);

	printf("\nAddress Details:\n");
	printf("Street: ");
	scanf(" %[^\n]%*c", record.address.street);

	printf("City: ");
	scanf(" %[^\n]%*c", record.address.city);

	printf("Pincode: ");
	scanf(" %[^\n]%*c", record.address.pincode);

	printf("\nTelephone: ");
	scanf(" %[^\n]%*c", record.telephone);

	//STORING RECORD ONTO FILE

	fprintf(fptr, "%s\n", record.name);
	fprintf(fptr, "%s\n", record.address.street);
	fprintf(fptr, "%s\n", record.address.city);
	fprintf(fptr, "%s\n", record.address.pincode);
	fprintf(fptr, "%s\n", record.telephone);

	printf("\n\nNEW ENTRY SUCCESSFULLY CREATED......!!!\n\n");
	printf("ENTER ANY CHARACTER TO EXIT: ");
	scanf(" %c", &exit);

	fclose(fptr);

}

void modify_record()
{


}

void display_record()
{
	system("clear");

	char name_key[size], exit;
	int flag=0;

	printf("+----------------------------+\n");
	printf("\tRETRIEVE A CONTACT\n");
	printf("+----------------------------+\n\n");

	printf("Enter Name: ");
	scanf("%s", name_key);
	printf("\n");

	fptr=fopen("contacts.txt", "r");

	while((fscanf(fptr," %[^\n]%*c\n", record.name))&&(!feof(fptr)))
	{	
		if(strcmp(record.name, name_key)==0)
		{
			//READING REMAINING DETAILS ONTO STRUCTURE
			
			fscanf(fptr, " %[^\n]%*c", record.address.street);
			fscanf(fptr, " %[^\n]%*c", record.address.street);
			fscanf(fptr, " %[^\n]%*c", record.address.city);
			fscanf(fptr, " %[^\n]%*c", record.address.pincode);
			fscanf(fptr, " %[^\n]%*c", record.telephone);

			//PRINTING DETAILS

			printf("Name: %s\n", record.name);
			printf("Address:\n");
			printf("%s\n", record.address.street);
			printf("%s - %s\n", record.address.city, record.address.pincode);
			printf("Telephone: %s\n\n", record.telephone);

			flag++;
		}
	}

	if(flag==1)
		printf("\n\nCONTACT FOUND SUCCESSFULLY......!!!\n\n");

	else if(flag>1)
		printf("\n\nMULTIPLE RECORDS FOUND......!!!\n\n");

	else if(flag==0)
		printf("\n\nNO CONTACT WITH ENTERED NAME FOUND......!!!\n\n");

	printf("ENTER ANY CHARACTER TO EXIT: ");
	scanf(" %c", &exit);

	fclose(fptr);	
}

void display_all()
{
	while(!feof(fptr))
	{	
		//READING REMAINING DETAILS ONTO STRUCTURE
		
		fscanf(fptr, " %[^\n]%*c", record.name);
		fscanf(fptr, " %[^\n]%*c", record.address.street);
		fscanf(fptr, " %[^\n]%*c", record.address.street);
		fscanf(fptr, " %[^\n]%*c", record.address.city);
		fscanf(fptr, " %[^\n]%*c", record.address.pincode);
		fscanf(fptr, " %[^\n]%*c", record.telephone);

		//PRINTING DETAILS

		printf("Name: %s\n", record.name);
		printf("Address:\n");
		printf("%s\n", record.address.street);
		printf("%s - %s\n", record.address.city, record.address.pincode);
		printf("Telephone: %s\n\n", record.telephone);
		
	}


}

int main()
{
	char choice, exit;

	do
	{
		system("clear");

		printf("+----------------------------+\n");
		printf("\tFILE OPTIONS\n");
		printf("+----------------------------+\n\n");

		printf("1. Add New Record\n\n");
		printf("2. Modify Existing Record\n\n");
		printf("3. Display Particular Record\n\n");
		printf("4. Display All Details\n\n");
		printf("5. EXIT\n\n");	

		printf("\n\nENTER choice: ");
		scanf(" %c", &choice);

		switch(choice)
		{
			case '1':	write_record();
					break;
		
			case '2':	modify_record();
					break;

			case '3':	display_record();
					break;

			case '4':	display_all();
					break;

			case '5':	remove("contacts");
					return 0;
					break;

			default:	printf("INVALID OPTION .....!!!!!\n\n");

					printf("PRESS ANY CHARACTER TO TRY AGAIN: ");
	scanf(" %c", &exit);
					

		}
	}while(choice!=5);

	
}