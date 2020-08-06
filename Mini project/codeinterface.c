#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<termios.h>
#include<string.h>

struct location
{
	char street[40];
	char city[25];
	char pincode[10];
	char state[25];
};

struct date
{
	int day;
	int month;
	int year;
};

struct user_details
{
	char username[40];
	char password[40];
	char name[40];
	struct location address;
	char nationality[40];
	char mobile[12];
	char email[45];
	struct date dob;
	int age;
	char gender;
};

// Identifiers used for admin login

#define USERNAME 	"admin"
#define PASSWORD		"admin20"

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


long int read_count_users(struct user_details all_users[])
{
	long int count=0;
	FILE *fptr=fopen("user.bin", "rb");

	fseek(fptr, 0, SEEK_END);
	count=(ftell(fptr))/sizeof(struct user_details);

	fseek(fptr, 0, SEEK_SET);
	
	for(int i=0; i<count; i++)
		fread(&all_users[i], sizeof(struct user_details), 1, fptr);		

	fclose(fptr);

	return count;
}

int search_users(int n, struct user_details all_users[])
{
	char search[40];
	
	printf("\n\tCURRENT Username: ");
	scanf("%s",search);

	for (int i=0; i<n; i++)
		if(strcmp(all_users[i].username, search)==0)
   	 		return i;
		
	return -1;
}

void user_det_update()
{
	struct user_details all_users[10];
	int count=0, index=-1;

	count=read_count_users(all_users);

	printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");

	index=search_users(count, all_users);

	FILE *fptr=fopen("user.bin", "wb");

	if(index!=-1)
	{		
		char ch;
	
		do
		{	system("clear");

			printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");

			printf("\n\n\t0. Username");
			printf("\n\n\t1. Password");
			printf("\n\n\t2. Name");
			printf("\n\n\t3. Address");
			printf("\n\n\t4. Nationality");
			printf("\n\n\t5. Mobile Number");
			printf("\n\n\t6. Email ID");
			printf("\n\n\t7. Date Of Birth");
			printf("\n\n\t8. Age");
			printf("\n\n\t9. Gender");
			printf("\n\n\te. BACK TO USER MENU");

			printf("\n\n\n\n\tEnter choice: ");
			scanf(" %c", &ch);
		
			switch(ch)
			{
				case '0':	system("clear");
						printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");
						printf("\n\n\tEnter the NEW Details\n\n");
						printf("\tUSERNAME: ");
						scanf(" %[^\n]", all_users[index].username);
						break;

				case '1':	system("clear");
						printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");
						printf("\n\n\tEnter the NEW Details\n\n");
						printf("\tPASSWORD: ");
						scanf(" %[^\n]", all_users[index].password);								break;

				case '2':	system("clear");
						printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");
						printf("\n\n\tEnter the NEW Details\n\n");
						printf("\n\tName: ");
						scanf(" %[^\n]", all_users[index].name);
						break;

				case '3':	system("clear");
						printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");
						printf("\n\n\tEnter the NEW Details\n\n");
						printf("\n\tAddress:\n");
						printf("\tStreet: ");
						scanf(" %[^\n]", all_users[index].address.street);
	
						printf("\tCity: ");
						scanf(" %[^\n]", all_users[index].address.city);

						printf("\tPincode: ");
						scanf(" %[^\n]", all_users[index].address.pincode);

						printf("\tState: ");
						scanf(" %[^\n]", all_users[index].address.state);
						break;

				case '4':	system("clear");
						printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");
						printf("\n\n\tEnter the NEW Details\n\n");				printf("\n\tNationality: ");
						scanf(" %[^\n]", all_users[index].nationality);
						break;

				case '5':	system("clear");
						printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");
						printf("\n\n\tEnter the NEW Details\n\n");
						printf("\tMobile: ");
						scanf(" %[^\n]", all_users[index].mobile);
						break;

				case '6':	system("clear");
						printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");
						printf("\n\n\tEnter the NEW Details\n\n");
						printf("\tEmail ID: ");
						scanf(" %[^\n]", all_users[index].email);
						break;

				case '7':	system("clear");
						printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");
						printf("\n\n\tEnter the NEW Details\n\n");
						printf("\n\tEnter DATE in dd mm yyyy FORMAT\n");
						printf("\tDate of birth: ");
						scanf("%d %d %d", &all_users[index].dob.day, &all_users[index].dob.month, &all_users[index].dob.year);
						break;

				case '8':	system("clear");
						printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");
						printf("\n\n\tEnter the NEW Details\n\n");
						printf("\n\tAge: ");
			scanf("%d", &all_users[index].age);
						break;

				case '9':	system("clear");
						printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");
						printf("\n\n\tEnter the NEW Details\n\n");
						printf("\n\tF: Female M: Male T:Transgender O:Other\n");
						printf("\tGender: ");
						scanf(" %c", &all_users[index].gender);
						break;
			
				case 'e':	printf("\n\n\n\tUPDATED USER ACCOUNT PROFILE SUCCESSFULLY...!!!\n");
						getch();
						break;

				default:	system("clear");
						printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE\n");
						printf("\n\nINVALID CHOICE\n");
						getch();

			}
		}while(ch!='e');

		fseek(fptr, 0, SEEK_SET);
		fwrite(&all_users, sizeof(struct user_details), count, fptr);

	}

	else
	{
		printf("\n\n\n\tUSER NOT FOUND...!!!");
		printf("\n\n\tINVALID USERNAME/DOESN'T EXIST...!!!\n");
	}

	fclose(fptr);

}

void user_det_delete()
{
	struct user_details all_users[10];
	int count=0, index=-1;

	printf("\n\n\n\tDELETE USER PROFILE\n\n");

	count=read_count_users(all_users);

	index=search_users(count, all_users);

	FILE *fptr=fopen("user.bin", "wb");

	if(index!=-1)
	{		
		for(int i=index; i<(count-1); i++)
			all_users[i]=all_users[i+1];

		fseek(fptr, 0, SEEK_SET);

		for(int i=0; i<(count-2); i++)
			fwrite(&all_users[i], sizeof(struct user_details), 1, fptr);
				
		printf("\n\n\n\tDELETEED USER ACCOUNT PROFILE SUCCESSFULLY...!!!\n");
	}

	else
	{
		printf("\n\n\n\tUSER NOT FOUND...!!!");
		printf("\n\n\tINVALID USERNAME/DOESN'T EXIST...!!!\n");
	}

	fclose(fptr);

	getch();
}

void user_det_view_particular()
{
	struct user_details all_users[10];
	int count=0, index=-1;

	printf("\n\n\n\tVIEW A PARTICULAR USER ACCOUNT PROFILE\n\n");

	count=read_count_users(all_users);

	index=search_users(count, all_users);

	if(index!=-1)
	{
		system("clear");

		printf("\n\n\n\tVIEW A PARTICULAR USER ACCOUNT PROFILE\n\n");

		printf("\tUSERNAME: %s\n", all_users[index].username);
	
		printf("\tPASSWORD: %s\n", all_users[index].password);
	
		printf("\n\tName: %s\n", all_users[index].name);
	
		printf("\n\tAddress:\n");
		printf("\t%s\n\t%s - %s\n\t%s\n", all_users[index].address.street, all_users[index].address.city, all_users[index].address.pincode, all_users[index].address.state);
	
		printf("\n\tNationality: %s\n", all_users[index].nationality);
	
		printf("\tMobile: %s\n", all_users[index].mobile);
	
		printf("\tEmail ID: %s\n", all_users[index].email);
	
		printf("\tDate of birth: %d-%d-%d\n", all_users[index].dob.day, all_users[index].dob.month, all_users[index].dob.year);
	
		printf("\n\tAge: %d\n", all_users[index].age);

		printf("\n\tF: Female M: Male T:Transgender O:Other\n");
		printf("\tGender: %c\n", all_users[index].gender);	
	}

	else
	{
		printf("\n\n\n\tUSER NOT FOUND...!!!");
		printf("\n\n\tINVALID USERNAME/DOESN'T EXIST...!!!\n");
	}
	
	getch();

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
	printf("\n\n\t\t5. Update Account Profile"); 
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
				user_det_view_particular();
				user_menu();
				break;

		case '5':	system("clear");
				user_det_update();
				user_menu();
				break;

		case '6':	system("clear");
				user_det_delete();
				break;

		case '7':	system("clear");
				break;

		default:	user_menu();
	}
}

void user_det_view_all()
{
	struct user_details all_users[10];
	int count=-1, i=0;
	FILE *fptr= fopen("user.bin", "rb");
	
	printf("\n\n\n\tVIEW All USER ACCOUNT PROFILE");

	count=read_count_users(all_users);

	if(count==0)
		count=-1;

	while((i<count))
	{
		printf("\n\n\tACCOUNT PROFILE DETAILS\n\n");

		printf("\tUSERNAME: %s\n", all_users[i].username);
	
		printf("\tPASSWORD: %s\n", all_users[i].password);
	
		printf("\n\tName: %s\n", all_users[i].name);
	
		printf("\n\tAddress:\n");
		printf("\t%s\n\t%s - %s\n\t%s\n", all_users[i].address.street, all_users[i].address.city, all_users[i].address.pincode, all_users[i].address.state);
	
		printf("\n\tNationality: %s\n", all_users[i].nationality);
	
		printf("\tMobile: %s\n", all_users[i].mobile);
	
		printf("\tEmail ID: %s\n", all_users[i].email);
	
		printf("\tDate of birth: %d-%d-%d\n", all_users[i].dob.day, all_users[i].dob.month, all_users[i].dob.year);
	
		printf("\n\tAge: %d\n", all_users[i].age);

		printf("\n\tF: Female M: Male T:Transgender O:Other\n");
		printf("\tGender: %c\n", all_users[i].gender);	

		i++;

		getch();

		system("clear");
	}

	fclose(fptr);	

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
	printf("\n\n\t\t5. View A Particular User Account Profile");  
	printf("\n\n\t\t6. View All User Account Profiles"); 
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
				user_det_view_particular();
				admin_menu();
				break;

		case '6':	system("clear");
				user_det_view_all();
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

void user_det_input()
{
	FILE *fptr= fopen("user.bin", "ab");
	struct user_details user;

	printf("\n\n\n\tSIGNUP\n\n");
	printf("\tNEW USER ACCOUNT ENTRY\n\n");

	printf("\tUSERNAME: ");
	scanf(" %[^\n]", user.username);

	printf("\tPASSWORD: ");
	scanf(" %[^\n]", user.password);

	printf("\n\tName: ");
	scanf(" %[^\n]", user.name);

	printf("\n\tAddress:\n");
	printf("\tStreet: ");
	scanf(" %[^\n]", user.address.street);
	
	printf("\tCity: ");
	scanf(" %[^\n]", user.address.city);

	printf("\tPincode: ");
	scanf(" %[^\n]", user.address.pincode);

	printf("\tState: ");
	scanf(" %[^\n]", user.address.state);

	printf("\n\tNationality: ");
	scanf(" %[^\n]", user.nationality);

	printf("\tMobile: ");
	scanf(" %[^\n]", user.mobile);

	printf("\tEmail ID: ");
	scanf(" %[^\n]", user.email);

	printf("\n\tEnter DATE in dd mm yyyy FORMAT\n");
	printf("\tDate of birth: ");
	scanf("%d %d %d", &user.dob.day, &user.dob.month, &user.dob.year);

	printf("\n\tAge: ");
	scanf("%d", &user.age);

	printf("\n\tF: Female M: Male T:Transgender O:Other\n");
	printf("\tGender: ");
	scanf(" %c", &user.gender);	

	fwrite(&user, sizeof(struct user_details), 1, fptr);

	fseek(fptr, 0, SEEK_END);

	fclose(fptr);


	printf("\n\n\n\tNEW USER ACCOUNT ENTRY SUCCESSFULL......!!!!!\n");

	getch();

}

void user_login()
{
	system("clear");	

	char pass[30];
	struct user_details all_users[10];
	int count=0, index=-1;

	printf("\n\n\n\tUSER LOGIN");	

	count=read_count_users(all_users);

	printf("\n");

	index=search_users(count, all_users);

	if(index==-1)
	{
		printf("\n\n\n\tUSERNAME INVALID....!!!!");
		getch();
	}
	
	else
	{	
		printf("\n\tPassword: ");
		getPassword(pass);

		if(strcmp(all_users[index].password, pass)==0)
			user_menu();

		else
		{
			printf("\n\n\n\tLOGIN FAILED....!!!!");
			getch();
		}
	
	}	

}

void user_terminal()
{
	char ch;

	system("clear");
	
	do
	{	system("clear");

		printf("\n\n\n\tSNL AIRLINE BOOKING");
		printf("\n\n\t1. LOGIN");
		printf("\n\n\t2. SIGNUP");
		printf("\n\n\t3. BACK TO MAIN MENU ");

		printf("\n\n\n\n\tEnter choice: ");
		scanf(" %c", &ch);
		
		switch(ch)
		{
			case '1':	system("clear");
					user_login();
					break;

			case '2':	system("clear");
					user_det_input();	
					break;

			case '3':	system("clear");
					break;
		}
	}while(ch!='3');

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
					user_terminal();
					break;

			case '2':	system("clear");
					admin_login();	
					break;

			case '3':	return 0;
		}
	}while(ch!='3');
}