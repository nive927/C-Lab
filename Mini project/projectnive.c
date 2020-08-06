#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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
	printf("file size: %ld\n", (ftell(fptr)));

	fclose(fptr);


	printf("\n\n\tNEW USER ACCOUNT ENTRY SUCCESSFULL......!!!!!\n\n");
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
	
	printf("Enter Username: ");
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

	printf("\n\n\n\tUPDATE USER ACCOUNT PROFILE");

	count=read_count_users(all_users);

	index=search_users(count, all_users);

	FILE *fptr=fopen("user.bin", "wb");

	if(index!=-1)
	{		
		printf("\n\n\tEnter the NEW Details\n\n");

		printf("\tUSERNAME: ");
		scanf(" %[^\n]", all_users[index].username);

		printf("\tPASSWORD: ");
		scanf(" %[^\n]", all_users[index].password);

		printf("\n\tName: ");
		scanf(" %[^\n]", all_users[index].name);

		printf("\n\tAddress:\n");
		printf("\tStreet: ");
		scanf(" %[^\n]", all_users[index].address.street);
	
		printf("\tCity: ");
		scanf(" %[^\n]", all_users[index].address.city);

		printf("\tPincode: ");
		scanf(" %[^\n]", all_users[index].address.pincode);

		printf("\tState: ");
		scanf(" %[^\n]", all_users[index].address.state);

		printf("\n\tNationality: ");
		scanf(" %[^\n]", all_users[index].nationality);

		printf("\tMobile: ");
		scanf(" %[^\n]", all_users[index].mobile);

		printf("\tEmail ID: ");
		scanf(" %[^\n]", all_users[index].email);

		printf("\n\tEnter DATE in dd mm yyyy FORMAT\n");
		printf("\tDate of birth: ");
		scanf("%d %d %d", &all_users[index].dob.day, &all_users[index].dob.month, &all_users[index].dob.year);

		printf("\n\tAge: ");
		scanf("%d", &all_users[index].age);

		printf("\n\tF: Female M: Male T:Transgender O:Other\n");
		printf("\tGender: ");
		scanf(" %c", &all_users[index].gender);	

		fseek(fptr, 0, SEEK_SET);
		fwrite(&all_users, sizeof(struct user_details), count, fptr);

		printf("\n\n\n\tUPDATED USER ACCOUNT PROFILE SUCCESSFULLY...!!!\n");
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
	}

	fclose(fptr);	

	getch();
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


int main()
{
	user_det_input();

	//user_det_view_all();

	//user_det_update();

	//user_det_view_particular();

	user_det_delete();

	user_det_view_all();
	
	return 0;
}



