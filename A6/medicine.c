#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define ws 45

struct Date
{
	int day;
	int month;
	int year;

};

struct Medicine
{
	char ID[ws];
	char Name[ws];
	char Vendor[ws];
	struct Date Manufacture;
	struct Date Expiry;
	float Cost;
	long int Stock;
};

int buy_drug(struct Medicine m[], int count)
{
	
	char drug_ID[ws], exit;
	long int quantity;
	
	printf("\n\nCHECKING IF DRUG EXISTS\n");

	printf("\nEnter Drug ID: ");
	scanf(" %[^\n]%*c", drug_ID);

	for(int i=0; i<count; i++)
	{
		if(strcmp(m[i].ID, drug_ID)==0)
		{
			printf("\n\nCurrent Stock: %ld\n", m[i].Stock);

			printf("\nBuy quantity: ");
			scanf("%ld", &quantity);

			m[i].Stock+=quantity;

			printf("\nUpdated Stock: %ld\n", m[i].Stock);

			printf("\n\nSTOCK UPDATED..........!!!!");

			printf("ENTER A CHARACTER TO EXIT: ");
			scanf(" %c", &exit);
			
			return count;		
		}
	}
	
	system("clear");

	printf("+----------------------------+\n");
	printf("\tNEW DRUG DETAILS\n");
	printf("+----------------------------+\n\n");

	printf("Drug ID: ");
	scanf(" %[^\n]%*c", m[count-1].ID);

	printf("Name: ");
	scanf("%[^\n]%*c", m[count-1].Name);

	printf("Vendor: ");
	scanf("%[^\n]%*c", m[count-1].Vendor);

	printf("DATE OF MANUFATURE IN dd/mm/yyyy FORMAT\n");
	scanf("%d %d %d", &m[count-1].Manufacture.day,			&m[count-1].Manufacture.month, &m[count-1].Manufacture.year);

	printf("EXPIRY DATE IN dd/mm/yyyy FORMAT\n");
	scanf("%d %d %d", &m[count-1].Expiry.day, &m[count-1].Expiry.month, &m[count-1].Expiry.year);

	printf("Cost: ");
	scanf("%f", &m[count-1].Cost);

	printf("Stock: ");
	scanf("%ld", &m[count-1].Stock);

	printf("\n\nNEW DRUG ENTRY SUCCESSFUL......!!!\n");

	printf("ENTER A CHARACTER TO EXIT: ");
	scanf(" %c", &exit);

	return ++count;

}

void sell_drug(struct Medicine m[], int count)
{

	system("clear");	

	printf("+----------------------------+\n");
	printf("\tSELL DRUG\n");
	printf("+----------------------------+\n\n");

	char drug_ID[ws], exit;
	long int quantity;
	int flag=0;

	printf("Enter Drug ID: ");
	scanf(" %[^\n]%*c", drug_ID);

	for(int i=0; i<count; i++)
	{
		if(strcmp(m[i].ID, drug_ID)==0)
		{
			flag=1;
			printf("Current Stock: %ld\n", m[i].Stock);

			printf("\nSell quantity: ");
			scanf("%ld", &quantity);

			if(quantity> m[i].Stock)
				printf("\n\nSTOCK INSUFFICIENT......!!\n");

			else
			{
				m[i].Stock-=quantity;

				printf("Updated Stock: %ld\n", m[i].Stock);
			}
		}
	}

	if(flag==1)
		printf("\n\nDRUG SOLD SUCCESSFULLY......!!!\n");

	else
	{	printf("\n\nINVALID DRUG ID....!!!\n");
		printf("DRUG NOT FOUND......!!\n");
	}

	printf("ENTER A CHARACTER TO EXIT: ");
	scanf(" %c", &exit);
}

void check_availability(struct Medicine m[], int count)
{
	system("clear");

	printf("+----------------------------+\n");
	printf("\tDRUG AVAILABILITY\n");
	printf("+----------------------------+\n\n");	

	char drug_ID[ws], exit;
	int flag=0;
	
	printf("Enter Drug ID: ");
	scanf(" %[^\n]%*c", drug_ID);

	for(int i=0; i<count; i++)
	{	if(strcmp(m[i].ID, drug_ID)==0)
		{	printf("Current Stock: %ld\n", m[i].Stock);
			flag=1;
			break;
		}
	}

	if(flag==1)
		printf("\n\nDRUG FOUND......!!!\n");
	else
	{	printf("\n\nINVALID DRUG ID......!!!\n");
		printf("DRUG NOT FOUND........!!!\n");
	}

	printf("\n\nENTER A CHARACTER TO EXIT: ");
	scanf(" %c", &exit);
	
}

void display_table(struct Medicine m[], int N)
{
	int ID_width= strlen(m[0].ID);
	for(int i=1; i<N; i++)
		if(strlen(m[i].ID)>ID_width)
			ID_width=strlen(m[i].ID);

	int nwidth= strlen(m[0].Name);
	for(int i=1; i<N; i++)
		if(strlen(m[i].Name)>nwidth)
			nwidth=strlen(m[i].Name);

	int vwidth= strlen(m[0].Vendor);
	for(int i=1; i<N; i++)
		if(strlen(m[i].Vendor)>vwidth)
			vwidth=strlen(m[i].Vendor);

	char ID[]="DRUG ID", nm[]="NAME", ve[]="VENDOR", ma[]="MANUFACTURE DATE", ex[]="EXPIRY DATE", co[]="COST", st[]="STOCK", exit;

	printf("%-*s%-*s%-*s%-19s%-14s%-8s%-8s\n", ID_width+4, ID, nwidth+4, nm, vwidth+4, ve, ma, ex, co, st);

	for(int i=0; i<N-1; i++)
	{		printf("%-*s%-*s%-*s%-5d%-5d%-9d%-4d%-4d%-6d%-8.2f%-8ld\n", ID_width+4, m[i].ID, nwidth+4, m[i].Name, vwidth+4, m[i].Vendor, m[i].Manufacture.day, m[i].Manufacture.month, m[i].Manufacture.year, m[i].Expiry.day, m[i].Expiry.month, m[i].Expiry.year, m[i].Cost, m[i].Stock);

	}

	printf("\n\nENTER A CHARACTER TO EXIT: ");
	scanf(" %c", &exit);

}

int main()
{	
	struct Medicine m[5];
	char choice;
	static int count=1;

	do
	{
		system("clear");

		printf("+----------------------------+\n");
		printf("\tADMIN OPTIONS\n");
		printf("+----------------------------+\n\n");

		printf("1. Buy New Drug\n\n");
		printf("2. Sell Drug\n\n");
		printf("3. Check Drug Avalaibilty\n\n");
		printf("4. Display Drug Details Table\n\n");
		printf("5. EXIT\n\n");	

		printf("\n\nENTER choice: ");
		scanf(" %c", &choice);

		switch(choice)
		{
			case '1':	count=buy_drug(m, count);
					break;
		
			case '2':	sell_drug(m, count);
					break;

			case '3':	check_availability(m, count);
					break;

			case '4':	display_table(m, count);
					break;

			case '5':	return 0;
					break;

			default: printf("INVALID OPTION .....!!!!!\n\n");

		}
	}while(choice!=5);
}



