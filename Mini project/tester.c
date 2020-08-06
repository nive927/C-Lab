#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<termios.h>
#include<string.h>

// Identifiers used for admin login

#define USERNAME 	"admin"
#define PASSWORD    	"admin20"

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
	printf("\n\t\t\t\t\t\t\t\t\t\t  Airline Reservation System");  
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

FILE *a, *f;
enum days {SUNDAY=1, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};
enum places{CHENNAI, BANGALORE, PUNE, DELHI, KOCHI, MUMBAI, HYDERABAD, SINGAPORE, LONDON, DUBAI};
typedef float price;
char place[][10]={"CHENNAI", "BANGALORE", "PUNE", "DELHI", "KOCHI", "MUMBAI", "HYDERABAD", "SINGAPORE", "LONDON", "DUBAI"};
char day[][10]={"", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

typedef struct
{
int code;
char pw[15];
}admin;

struct time
{
int hh;
int mm;
};

struct flight_det
{
int acode;               	//airline code
char fcode[10];
enum places source;
enum places destination;
struct time deptime;
struct time arrtime;
enum days day;
price adult_first;
price adult_business;
price adult_economy;
price child_first;
price child_business;
price child_economy;
};

void add_flights(int n, int acode)
{
struct flight_det flight;
int day;
for (int i=0;i<n;i++)
{
    flight.acode=acode;
    printf("Enter flight code: ");
    scanf(" %5s",flight.fcode);
    printf("Source Options:\n\t0. CHENNAI\n\t1. BANGALORE\n\t2. PUNE\n\t3. DELHI\n\t4. KOCHI\n\t5. MUMBAI\n\t6. HYDERABAD\n\t7. SINGAPORE\n\t8. LONDON\n\t9. DUBAI\n");
    printf("Enter option: ");
    scanf(" %u",&flight.source);
    printf("Destination Options:\n\t0. CHENNAI\n\t1. BANGALORE\n\t2. PUNE\n\t3. DELHI\n\t4. KOCHI\n\t5. MUMBAI\n\t6. HYDERABAD\n\t7. SINGAPORE\n\t8. LONDON\n\t9. DUBAI\n");
    printf("Enter option: ");
    scanf(" %u",&flight.destination);
    printf("Enter departure time(hh/mm) : ");
    scanf("%d/%d",&flight.deptime.hh,&flight.deptime.mm);
    printf("Enter arrival time(hh/mm)   : ");
    scanf("%d/%d",&flight.arrtime.hh,&flight.arrtime.mm);
    printf("Day of operation of flight option:\n\t1. Sundays\n\t2. Mondays\n\t3. Tuesdays\n\t4. Wednesdays\n\t5. Thursdays\n\t6. Fridays\n\t7. Saturdays\nEnter choice: ");
    scanf("%d",&day);
    switch (day)
    {
    case 1: flight.day=SUNDAY;
    break;    
    case 2: flight.day=MONDAY;
    break;    
    case 3: flight.day=TUESDAY;
    break;    
    case 4: flight.day=WEDNESDAY;
    break;    
    case 5: flight.day=THURSDAY;
    break;    
    case 6: flight.day=FRIDAY;
    break;    
    case 7: flight.day=SATURDAY;
    break;    
    }
    printf("Adult ticket prices\n");
    printf("\tEnter for first class	: ");
    scanf("%f",&flight.adult_first);
    printf("\tEnter for business class : ");
    scanf("%f",&flight.adult_business);
    printf("\tEnter for economy class  : ");
    scanf("%f",&flight.adult_economy);
    printf("Child ticket prices\n");
    printf("\tEnter for first class	: ");
    scanf("%f",&flight.child_first);
    printf("\tEnter for business class : ");
    scanf("%f",&flight.child_business);
    printf("\tEnter for economy class  : ");
    scanf("%f",&flight.child_economy);

    fwrite(&flight, sizeof(struct flight_det), 1, f);
}
}


int read_det(int acode, struct flight_det allflight[])
{
int count;
fseek(f, 0, SEEK_END);
count=ftell(f)/sizeof(struct flight_det);
fseek(f, 0, SEEK_SET);
fread(allflight, sizeof(struct flight_det), count, f);
return count;
}


void display(int i,struct flight_det allflight[])
{
printf("%-5d %-5s %-10s %-10s   %02d:%02d 	%02d:%02d   %-9s %10.2f%10.2f%10.2f%10.2f%10.2f%10.2f\n", allflight[i].acode, allflight[i].fcode, place[allflight[i].source], place[allflight[i].source], allflight[i].deptime.hh, allflight[i].deptime.mm, allflight[i].arrtime.hh, allflight[i].arrtime.mm, day[allflight[i].day], allflight[i].adult_first, allflight[i].adult_business, allflight[i].adult_economy, allflight[i].child_first, allflight[i].child_business, allflight[i].child_economy);
}

int search(int n, struct flight_det allflight[])
{
char search[20];
printf("Enter flight code: ");
scanf(" %s",search);
for (int i=0;i<n;i++)
{
    if(strcmp(allflight[i].fcode,search)==0)
   	 return i;
}
return -1;
}


void modify(int index,int n,struct flight_det allflight[])
{
int day;
printf("Source Options:\n\t0. CHENNAI\n\t1. BANGALORE\n\t2. PUNE\n\t3. DELHI\n\t4. KOCHI\n\t5. MUMBAI\n\t6. HYDERABAD\n\t7. SINGAPORE\n\t8. LONDON\n\t9. DUBAI\n");
printf("Enter new option: ");
scanf(" %u",&allflight[index].source);
printf("Destination Options:\n\t0. CHENNAI\n\t1. BANGALORE\n\t2. PUNE\n\t3. DELHI\n\t4. KOCHI\n\t5. MUMBAI\n\t6. HYDERABAD\n\t7. SINGAPORE\n\t8. LONDON\n\t9. DUBAI\n");
printf("Enter new option: ");
scanf(" %u",&allflight[index].destination);
printf("Enter new departure time(hh/mm) : ");
scanf("%d/%d",&allflight[index].deptime.hh,&allflight[index].deptime.mm);
printf("Enter new arrival time(hh/mm)   : ");
scanf("%d/%d",&allflight[index].arrtime.hh,&allflight[index].arrtime.mm);
printf("Day of operation of flight option:\n\t1. Sundays\n\t2. Mondays\n\t3. Tuesdays\n\t4. Wednesdays\n\t5. Thursdays\n\t6. Fridays\n\t7. Saturdays\nEnter new choice: ");
scanf("%d",&day);
switch (day)
    {
    case 1: allflight[index].day=SUNDAY;
    break;    
    case 2: allflight[index].day=MONDAY;
    break;    
    case 3: allflight[index].day=TUESDAY;
    break;    
    case 4: allflight[index].day=WEDNESDAY;
    break;    
    case 5: allflight[index].day=THURSDAY;
    break;    
    case 6: allflight[index].day=FRIDAY;
    break;    
    case 7: allflight[index].day=SATURDAY;
    break;    
    }
printf("Adult new ticket prices\n");
printf("\tEnter for first class	: ");
scanf("%f",&allflight[index].adult_first);
printf("\tEnter for business class : ");
scanf("%f",&allflight[index].adult_business);
printf("\tEnter for economy class  : ");
scanf("%f",&allflight[index].adult_economy);
printf("Child new ticket prices\n");
printf("\tEnter for first class	: ");
scanf("%f",&allflight[index].child_first);
printf("\tEnter for business class : ");
scanf("%f",&allflight[index].child_business);
printf("\tEnter for economy class  : ");
scanf("%f",&allflight[index].child_economy);

fseek(f, 0, SEEK_SET);
fwrite(allflight, sizeof(struct flight_det), n, f);
}

void delete(int index,int n,struct flight_det allflight[])
{
for (int i=index;i<n;i++)
    allflight[i]=allflight[i+1];
fwrite(allflight,sizeof(struct flight_det),--n,f);
printf("Flight Record Deleted!!\n");
}


void admin_menu(int acode)
{
	system("clear");

	char ch, file[10];
	int n,index;
	struct flight_det flight, allflight[20];
	if (acode==123)
    strcpy(file,"123.bin");
	else if (acode==456)
    strcpy(file,"456.bin");
	else if (acode==789)
    strcpy(file,"789.bin");
    
	printf("\n\n\n\tADMINISTRATOR OPTIONS");  
	printf("\n\n\tFLIGHT OPTIONS");
	printf("\n\n\t\t1. Add New Flight");
	printf("\n\n\t\t2. Update Existing Flight");
	printf("\n\n\t\t3. Delete A Particular Flight");   
	printf("\n\n\t\t4. Display A Particular Flight");  
	printf("\n\n\t\t5. Display All Flights");
	printf("\n\n\tCUSTOMER OPTIONS");  
	printf("\n\n\t\t6. View A Particular User Record");  
	printf("\n\n\t\t7. View All User Records");
	printf("\n\n\tEXIT OPTION");
	printf("\n\n\t\t8. BACK TO MAIN MENU");    

	printf("\n\n\n\n\tEnter choice: ");
	scanf(" %c", &ch);
 
	switch(ch)
 
	{
    	case '1':	system("clear");
   	 f=fopen(file,"ab+");
   	 printf("Enter number of flights to be added: ");
   	 scanf("%d",&n);
   	 add_flights(n,acode);
   	 fclose(f);    
   			 
            	admin_menu(acode);
            	break;

    	case '2':	system("clear");
            	f=fopen(file,"rb+");
   	 n=read_det(acode, allflight);
   	 index=search(n, allflight);
   	 if (index==-1)
   		 printf("\nFlight details not found!!\n");
   	 else
   		 modify(index,n,allflight);
   	 fclose(f);
            	admin_menu(acode);
            	break;

    	case '3':	system("clear");
   	 f=fopen(file,"rb");
   	 n=read_det(acode, allflight);
   	 index=search(n, allflight);
   	 if (index==-1)
   		 printf("\nFlight details not found!!\n");
   	 else
   		 {
   		 f=fopen(file,"wb");
   		 delete(index,n,allflight);
		getch();
   		 }
   	 fclose(f);
            	admin_menu(acode);
            	break;

    	case '4':	system("clear");
            	f=fopen(file,"rb");
   	 n=read_det(acode, allflight);
   	 index=search(n, allflight);
   	 if (index==-1)
   		 printf("\nFlight code does not exist!!\n");
   	 else
   	 {
printf("ACODE FCODE SOURCE	DESTINATION  DEPARTURE ARRIVAL	DAY            	ADULT FARES                	CHILD FARES\n");
printf("                                                                	FIRST	BUSINESS  ECONOMY 	FIRST	BUSINESS  ECONOMY\n");
   		 display(index, allflight);
   	 }
   	 fclose(f);
	getch();
   	 admin_menu(acode);
   		 break;

    	case '5':	system("clear");
            	f=fopen(file,"rb");
   	 n=read_det(acode, allflight);
printf("ACODE FCODE SOURCE	DESTINATION  DEPARTURE ARRIVAL	DAY            	ADULT FARES                	CHILD FARES\n");
printf("                                                                	FIRST	BUSINESS  ECONOMY 	FIRST	BUSINESS  ECONOMY\n");
   	 for (int i=0;i<n-1;i++)
   	 {
   		 display(i,allflight);
   	 }
   	 fclose(f);
		getch();
   	 admin_menu(acode);
  		      break;

    	case '6':	system("clear");
            	admin_menu(acode);
            	break;

    	case '7':	system("clear");
            	admin_menu(acode);
            	break;

    	case '8':	system("clear");
            	break;

    	default:	admin_menu(acode);
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




void admin_add()
{
a=fopen("admin_det.bin","wb");
admin alldet[3];
alldet[0].code=123;
strcpy(alldet[0].pw,"abc");
alldet[1].code=456;
strcpy(alldet[1].pw,"def");
alldet[2].code=789;
strcpy(alldet[2].pw,"ghi");
fwrite(alldet, sizeof(admin), 3, a);
fclose(a);
}

int check(admin det)
{
int count;    
a=fopen("admin_det.bin","rb");
fseek(a, 0, SEEK_END);
count=ftell(a)/sizeof(admin);
admin alldet[count];
fseek(a, 0, SEEK_SET);
fread(alldet, sizeof(admin), count, a);
for(int i=0;i<count;i++)
    if (det.code==alldet[i].code && strcmp(det.pw,alldet[i].pw)==0)
   	 return det.code;
return 0;    
}


void admin_login()
{
	system("clear"); 	 
	admin det;

	int user;
	char pass[30];

	printf("\n\n\n\t\tADMIN LOGIN");    
	printf("\n\n\n\t\tAirline code: ");    
	scanf(" %d", &det.code);
	printf("\n\t\tPassword: ");
	getPassword(det.pw);

	if (check(det))
    admin_menu(det.code);
   	 
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

        	case '2':	system("clear");                         	admin_login();    
                	break;

        	case '3':	return 0;
    	}
	}while(ch!='3');
}