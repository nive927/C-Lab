#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<termios.h>
#include<string.h>

// Identifiers used for admin login

#define USERNAME 	"admin"
#define PASSWORD	"admin20"

/* Function to implement getch() due to absence of <conio.h> in gcc compliler */

char getch()
{
	char buf=0;

	struct termios old={0};

	fflush(stdout);

	if(tcgetattr(0, &old)<0)
		perror("tcsetattr()");

	old.c_lflag&=~ICANON;
    	old.c_lflag&=~ECHO;
    	old.c_cc[VMIN]=1;
    	old.c_cc[VTIME]=0;

	if(tcsetattr(0, TCSANOW, &old)<0)
		perror("tcsetattr ICANON");

	if(read(0,&buf,1)<0)
		perror("read()");

	old.c_lflag|=ICANON;
   	old.c_lflag|=ECHO;

	if(tcsetattr(0, TCSADRAIN, &old)<0)
		perror ("tcsetattr ~ICANON");

	return buf;
 }

// Function to display the introductory opening page

void intro()
{
	system("clear");

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t  MINI PROJECT\n");
	printf("\n\t\t\t\t\t\t\t\t\t\t  Airplane Reservation System");
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\tMADE BY: Lakshmi Priya 185001083\n \t\t\t\t\t\t\t\t\t\t\t Nivedhitha D  185001104\n\t\t\t\t\t\t\t\t\t\t\t Sakthi Sairaj 185001134\n\n");
  	printf("\t\t\t\t\t\t\t\t\t\tBRANCH : CSE B\n");
	printf("\n\t\t\t\t\t\t\t\t\t\tCOLLEGE: SSN College of Engineering\n");

	getch();
}

void ticket_enquiry()
{
	system("clear");

	char ch;

	printf("\n\n\n\tBOOKED TICKET ENQUIRY");
	printf("\n\n\tTICKET OPTIONS");
	printf("\n\n\t\t1. View Particular Flight Ticket");
	printf("\n\n\t\t2. View All Flight Tickets");
	printf("\n\n\tBILL OPTIONS");
	printf("\n\n\t\t3. View A Particular Bill");
	printf("\n\n\t\t4. View All Bills");
	printf("\n\n\tEXIT OPTION");
	printf("\n\n\t\t5. BACK TO USER MENU");

	printf("\n\n\n\n\tEnter choice: ");
	scanf(" %c", &ch);

	switch(ch)

	{
		case '1':	system("clear");
				getch();
				ticket_enquiry();
				break;

		case '2':	system("clear");
				getch();
				ticket_enquiry();
				break;

		case '3':	system("clear");
				getch();
				ticket_enquiry();
				break;

		case '4':	system("clear");
				getch();
				ticket_enquiry();
				break;

		case '5':	system("clear");
				break;

		default:	ticket_enquiry();
	}
}

void user_menu()
{
	system("clear");

	char ch;

	printf("\n\n\n\tUSER OPTIONS");
	printf("\n\n\tTICKET OPTIONS");
	printf("\n\n\t\t1. Book Flight Ticket");
	printf("\n\n\t\t2. Current Flight Ticket Bookings");
	printf("\n\n\t\t3. Cancel Flight Ticket");
	printf("\n\n\tACCOUNT OPTIONS");
	printf("\n\n\t\t4. View Account Profile");
	printf("\n\n\t\t5. Update Account Details");
	printf("\n\n\t\t6. Delete Account");
	printf("\n\n\tEXIT OPTION");
	printf("\n\n\t\t7. BACK TO MAIN MENU");

	printf("\n\n\n\n\tEnter choice: ");
	scanf(" %c", &ch);

	switch(ch)

	{
		case '1':	system("clear");
				getch();
				user_menu();
				break;

		case '2':	system("clear");
				ticket_enquiry();
				user_menu();
				break;

		case '3':	system("clear");
				getch();
				user_menu();
				break;

		case '4':	system("clear");
				getch();
				user_menu();
				break;

		case '5':	system("clear");
				getch();
				user_menu();
				break;

		case '6':	system("clear");
				getch();
				user_menu();
				break;

		case '7':	system("clear");
				break;

		default:	user_menu();
	}
}

void admin_menu()
{
	system("clear");

	char ch;

	printf("\n\n\n\tADMINISTRATOR OPTIONS");
	printf("\n\n\tFLIGHT OPTIONS");
	printf("\n\n\t\t1. Add New Flight");
	printf("\n\n\t\t2. Update Existing Flight");
	printf("\n\n\t\t3. Display A Particular Flight");
	printf("\n\n\t\t4. Display All Flights");
	printf("\n\n\tCUSTOMER OPTIONS");
	printf("\n\n\t\t5. View A Particular User Record");
	printf("\n\n\t\t6. View All User Records");
	printf("\n\n\tEXIT OPTION");
	printf("\n\n\t\t7. BACK TO MAIN MENU");

	printf("\n\n\n\n\tEnter choice: ");
	scanf(" %c", &ch);

	switch(ch)

	{
		case '1':	system("clear");
				getch();
				admin_menu();
				break;

		case '2':	system("clear");
				getch();
				admin_menu();
				break;

		case '3':	system("clear");
				getch();
				admin_menu();
				break;

		case '4':	system("clear");
				getch();
				admin_menu();
				break;

		case '5':	system("clear");
				getch();
				admin_menu();
				break;

		case '6':	system("clear");
				getch();
				admin_menu();
				break;

		case '7':	system("clear");
				break;

		default:	admin_menu();
	}
}

/*  To get the password from the keyboard.
Uses pass by reference to get the entered password
via parameter to function  */

void getPassword(char *pass)
{
	char ch;
  	int len=0;

	while((ch=getch())!='\n')
  	{
		printf("*");

		pass[len]=ch;
		len++;
  	}

	pass[len]='\0';
}

void admin_login()
{
	system("clear");

	char user[30],pass[30];

	printf("\n\n\n\t\tADMIN LOGIN");
	printf("\n\n\n\t\tUser Name: ");
	scanf(" %[^\n]", user);
	printf("\n\t\tPassword: ");
	getPassword(pass);

	if( strcmp(user,USERNAME)==0 && strcmp(pass,PASSWORD)==0)
		admin_menu();

	else
	{
		printf("\n\n\n\t\tLOGIN FAILED....!!!!");
		getch();
	}
}

int main()
{
	char ch;
	intro();

	do
	{	system("clear");

		printf("\n\n\n\tMAIN MENU");
		printf("\n\n\t1. USER");
		printf("\n\n\t2. ADMINISTRATOR");
		printf("\n\n\t3. EXIT");

		printf("\n\n\n\n\tEnter choice: ");
		scanf(" %c", &ch);

		switch(ch)
		{
			case '1':	system("clear");
					user_menu();
					break;

			case '2':	system("clear");
					admin_login();
					break;

			case '3':	return 0;
		}
	}while(ch!='3');
}