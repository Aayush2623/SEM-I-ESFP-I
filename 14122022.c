#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char login();
char main_menu();
char user_records();
char land_records();
char user_records_new_user();
char user_records_view_user();
char land_records_new_rec();
char land_records_view_rec();
char file_handling_user();
char file_handling_land();
struct loop1{
	int i;
	int j;
	int k;
}a;
struct loop2{
	int x;
	int y;
	int z;
}b;
struct login{
    char userid[20];
    char password[20];
} lg;
struct user{
    char name[20];
    char mob[11];
    char address[20];
    char dob[8];
    int c;
} us[5];
struct land{
	char id[10];
	char district[20];
	char type[20];
	char sub_reg_office[20];
	char survey[20];
	char sheet_no[20];
}ld[5];

char login()
{
    int x,y;
    printf("=======================================================LOGIN PAGE=======================================================\n");
	printf("Enter your userid:");
    scanf("%s",lg.userid);
    printf("Enter your password:");
    scanf("%s",lg.password);
    x=strcmp(lg.userid,"admin");
    if(x==0)
    {
        y=strcmp(lg.password,"admin123");
        if(y==0)
        {
            printf("Login Successfull\n");
            main_menu();
        }
        else
        {
            printf("Invalid Password");
        }
    }
    else
    {
        printf("Invalid Username");
    }
}
char main_menu()
{
    int choice;
    printf("========================================================MAIN MENU=======================================================\n");
    printf("Press 1 for User Records\n");
    printf("Press 2 for Land Records\n");
    printf("Press 0 to Exit\n");
    printf("Enter Your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        user_records();
        break;
        case 2:
        land_records();
        break;
        case 0:
        break;
        default:
        printf("Invalid choice");
        break;
    }
}
char user_records()
{
    int choice1;
    printf("======================================================USER RECORDS======================================================\n");
    printf("Press 1 to Add New User\n");
    printf("Press 2 to View Existing User\n");
    printf("Press 3 to go to Main Menu\n");
    printf("Press 0 to Exit\n");
    printf("Enter Your Choice:");
    scanf("%d",&choice1);
    switch(choice1)
    {
        case 1:
        user_records_new_user();
        break;
        case 2:
        user_records_view_user();
        break;
        case 3:
        main_menu();
        break;
        case 0:
        break;
        default:
        printf("Invalid choice");
        break;
    }
}
char user_records_new_user()
{
    printf("------------------------------------------------------ADD NEW USER------------------------------------------------------\n");
    printf("Enter your Name:");
    fflush(stdin);
    gets(us[a.i].name);
    printf("Enter your Mobile number:");
    fflush(stdin);
    gets(us[a.i].mob);
    printf("Enter your Address:");
    fflush(stdin);
    gets(us[a.i].address);
    printf("Enter your Date of Birth(DDMMYYYY):");
    fflush(stdin);
    gets(us[a.i].dob);
    printf("User added Successfully\n");
    a.i++;
    a.k=a.i;
    file_handling_user();
    user_records();
}

char user_records_view_user()
{
        printf("------------------------------------------------------VIEW RECORDS------------------------------------------------------\n");
        for(a.j=0;a.j<a.k;a.j++)
        {
		printf("Name: %s\n",us[a.j].name);
        printf("Mobile NO: %s\n",us[a.j].mob);
        printf("Address: %s\n",us[a.j].address);
        printf("Date of Birth: %s\n",us[a.j].dob);
        }
        user_records();
}
char land_records()
{
    int choice1;
    printf("======================================================LAND RECORDS======================================================\n");
    printf("Press 1 to Add New Land Record\n");
    printf("Press 2 to View Existing Land Records\n");
    printf("Press 3 to go to Main Menu\n");
    printf("Press 0 to Exit\n");
    printf("Enter Your Choice:");
    scanf("%d",&choice1);
    switch(choice1)
    {
        case 1:
        land_records_new_rec();
        break;
        case 2:
        land_records_view_rec();
        break;
        case 3:
        main_menu();
        break;
        case 0:
        break;
        default:
        printf("Invalid choice");
        break;
    }
}
char land_records_new_rec()
{
    printf("-----------------------------------------------------ADD NEW RECORD-----------------------------------------------------\n");
    printf("Enter your user id:");
    fflush(stdin);
    gets(ld[b.x].id);
	printf("Enter your District:");
	fflush(stdin);
    gets(ld[b.x].district);
    printf("Enter your Land Type:");
    fflush(stdin);
    gets(ld[b.x].type);
    printf("Enter your Sub-Registar Office:");
    fflush(stdin);
    gets(ld[b.x].sub_reg_office);
    printf("Enter your Survey No.:");
    fflush(stdin);
    gets(ld[b.x].survey);
    printf("Enter your Sheet No.:");
    fflush(stdin);
    gets(ld[b.x].sheet_no);
    printf("Record added Successfully\n");
    b.x++;
    b.z=b.x;
    file_handling_land();
    land_records();
}
char land_records_view_rec()
{
        printf("------------------------------------------------------VIEW RECORDS------------------------------------------------------\n");
        for(b.y=0;b.y<b.z;b.y++)
        {
		printf("User Id: %s\n",ld[b.y].id);
        printf("District: %s\n",ld[b.y].district);
        printf("Land Type: %s\n",ld[b.y].type);
        printf("Sub-Registar Office: %s\n",ld[b.y].sub_reg_office);
        printf("Survey No.: %s\n",ld[b.y].survey);
        printf("Sheet No.: %s\n",ld[b.y].sheet_no);
        }
        land_records();
}
char file_handling_user()
{
	FILE *p;
	p=fopen("pid_user.txt","w");
	for(a.j=0;a.j<a.k;a.j++){
	fprintf(p,"Name: %s\nMobile No.: %s\nAddress: %s\nDate of birth: %s\n\n",us[a.j].name,us[a.j].mob,us[a.j].address,us[a.j].dob);
	}
	fclose(p);
}
char file_handling_land()
{
	FILE *p;
	p=fopen("pid_land.txt","w");
	for(b.y=0;b.y<b.z;b.y++){
	fprintf(p,"ID: %s\nDistrict: %s\nType: %s\nSub-Registar Office: %s\nSurvey: %s\nSheet No.: %s\n\n",ld[b.y].id,ld[b.y].district,ld[b.y].type,ld[b.y].sub_reg_office,ld[b.y].survey,ld[b.y].sheet_no);
	}
	fclose(p);
}

int main()
{
    printf("\t\t\t================================================================================\n");
	printf("\t\t\t********************************************************************************\n");
	printf("\n\t\t\t                                  PID - 108                                 \n");
	printf("\t\t\t                          Land Records For Revenue Department                 \n");
	printf("\t\t\t                          Developed by : Aayush Gajjar                        \n");
	printf("\t\t\t                            For the Academic Year :                           \n");
	printf("\t\t\t                                  2022-2023                                   \n");
	printf("\t\t\t                            Branch : Cyber Security                           \n");
	printf("\t\t\t                             Enrollment No. : CS03                            \n");
	printf("\n\t\t\t********************************************************************************\n");
	printf("\t\t\t================================================================================\n");
	login();
    return 0;
}
