/*--------------------------------------------------

            #GRC Memeber Management System.
            #By: Devrajsinh Gohil
            #PI task
            
----------------------------------------------------*/

// header files reqired
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>


// data structure for member details
typedef struct data
{
    char first_name[50];
    char last_name[50];
    int age;
    double enr;
    char college_name[200];
    int year;
    char grc_id[15];
    char grc_dpt[100];
}data;

// function prototypes
void add_data(void);
void show_data(void);
void search_data(void);
void delete_data(void);
void out(void);
void print_data(data);
void up(char s[]);
void check_alpha(char s[]);
void check_num(int);
void check_id(char s[]);

// main function to show menu and used switch case for the input from menu by user.
int main()
{
    system("clear");
    int response = 0;
    while (response != 5)
    {
        printf("\t\t\t========== GRC Student Database Management ==========");
        printf("\n\n\n\t\t\t 1. Add Member Data ");
        printf("\n\t\t\t 2. Member List");
        printf("\n\t\t\t 3. Search Member");
        printf("\n\t\t\t 4. Remove Member");
        printf("\n\t\t\t 5. Exit\n");
        printf("\t\t\t-----------------------------------------------------\n");
        printf("\t\t\tEnter: ");
        scanf("%d", &response);
        switch (response) {
            case 1:
                system("clear");
                add_data();
                system("clear");
                break;
            case 2:
                system("clear");
                show_data();
                out();
                system("clear");
                break;
            case 3:
                system("clear");
                search_data();
                out();
                system("clear");
                break;
            case 4:
                system("clear");
                delete_data();
                out();
                system("clear");
                break;
          case 5:
                break;
            default:printf("Invalid input");
        }
    }
    system("clear");
    return 0;
}

// add_data function adds new member's data into database
void add_data()
{
    char rep = 'y';
    FILE *fp;
    data info;
    do
    {
        fp = fopen("grc_members.txt", "a");
        printf("\t\t\t========== Add Member Data ==========");
        printf("\n\n\n\t\t\t Enter First name: ");
        scanf("%s", info.first_name);
        check_alpha(info.first_name);
        up(info.first_name);
        printf("\n\t\t\t Enter Last name: ");
        scanf("%s", info.last_name);
        check_alpha(info.last_name);
        up(info.last_name);
        printf("\n\t\t\t Enter Age: ");
        check_num(scanf("%d", &info.age));
        printf("\n\t\t\t GTU Enrollment no.:");
        check_num(scanf("%lf", &info.enr));
        printf("\n\t\t\t College Name (type without any space): ");
        scanf("%s", info.college_name);
        check_alpha(info.college_name);
        up(info.college_name);
        printf("\n\t\t\t Current Year: ");
        check_num(scanf("%d", &info.year));
        printf("\n\t\t\t GRC id (Please enter alphabets in Capital): ");
        scanf("%s", info.grc_id);
        check_id(info.grc_id);
        up(info.grc_id);
        printf("\n\t\t\t GRC Department: ");
        scanf("%s", info.grc_dpt);
        check_alpha(info.grc_dpt);
        up(info.grc_dpt);
        printf("\n\t\t\t-----------------------------------------------------\n");

        // error handling
        if (fp == NULL)
        {
            fprintf(stderr, "File not found!\n");
        }
        else
        {
            printf("Data stored successfully.\n");
            fwrite(&info, sizeof(data), 1, fp);
        }
        fclose(fp);
        printf("Do you to add another member? (y/n): ");
        scanf("%s",&rep);
        rep = tolower(rep);

        // yes or no validation for next operation
        do
        {
            if (rep != 'y' && rep != 'n')
            {
                printf("Please enter valid input! (y/n): ");
                scanf("%s",&rep);
            }
        } while (rep != 'y' && rep != 'n');

    } while (rep == 'y');
}

// function to show data of all the members
void show_data()
{
    FILE *fp;
    data info;

    // error handling
    fp = fopen("grc_members.txt", "r");

    if (fp == NULL)
    {
        fprintf(stderr, "File not found!\n");
        sleep(3);
    }
    else
    {
        printf("\t\t\t========== Member List ==========\n\n\n");
        while(fread(&info,sizeof(data),1,fp))
        {
            print_data(info);
        }
        fclose(fp);
    }
}

// function to search data of a particular member
void search_data(void)
{
    char id[15];
    int found = 0;
    FILE *fp;
    data info;
    fp = fopen("grc_members.txt", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "File not found!\n");
        sleep(3);
    }
    else
    {
        printf("\t\t\t========== Search Member ==========\n\n\n");
        printf("\t\t\tEnter GRC Id: ");
        scanf("%s", id);
        printf("\n");
        while(fread(&info,sizeof(data),1,fp))
        {
            if(strcmp(info.grc_id,id) == 0)
            {
                found = 1;
                print_data(info);
            }
        }
        if(!found)
        {
            printf("\t\t\tNo match found!!\n");
        }
        fclose(fp);
    }
}

// function to delete data of aparticular member
void delete_data(void)
{
    char id[15];
    int found = 0;
    FILE *fp,*fp1;
    data info;
    fp = fopen("grc_members.txt", "r");
    fp1 = fopen("temp.txt", "w");

    // error handling
    if (fp == NULL)
    {
        fprintf(stderr, "File not found!\n");
        sleep(3);
    }
    else
    {
        printf("\t\t\t========== Remove Member ==========\n\n\n");
        printf("\t\t\tEnter GRC Id: ");
        scanf("%s", id);
        printf("\n");
        while(fread(&info,sizeof(data),1,fp)){
            if(strcmp(info.grc_id, id) == 0){
                found=1;
            }
            else
            {
                fwrite(&info,sizeof(data),1,fp1);
            }

        }
        fclose(fp);
        fclose(fp1);

        if(!found){
            printf("\n\t\t\t\tRecord not found\n");
        }
        if(found){
            remove("grc_members.txt");
            rename("temp.txt","grc_members.txt");
            printf("\n\t\t\t\tRecord deleted succesfully\n");
        }
    }
}

// exit function to get out an option of menu
void out(void)
{
    int ex = 1;
    while(ex != 0)
    {
        printf("\nPlease enter 0 to return: ");
        if (scanf("%d", &ex) != 1)
        {
            system("clear");
            printf("You should enter a valid input!!");
            sleep(3);
            system("clear");
            exit(0);
        }
    }
}

// function to print a member data
void print_data(data info)
{
    printf("\t\t\tName: %s %s\n", info.first_name, info.last_name);
    printf("\t\t\tAge: %d\n", info.age);
    printf("\t\t\tGTU Enrollment number: %0.0lf\n", info.enr);
    printf("\t\t\tCollege Name: %s\n", info.college_name);
    printf("\t\t\tCurrent Year: %d\n", info.year);
    printf("\t\t\tGRC id: %s\n", info.grc_id);
    printf("\t\t\tGRC dpt: %s\n", info.grc_dpt);
    printf("\t\t\t___________________________________\n\n");
}

// function to uppercase the alphabets in a string literal
void up(char s[])
{
    for (int i = 0; s[i]!='\0'; i++) {
      if(s[i] >= 'a' && s[i] <= 'z') {
         s[i] = toupper(s[i]);
      }
   }
}

// data validation for alphabets only input
void check_alpha(char s[])
{
    for (int i = 0; s[i]!='\0'; i++) {
      if(isdigit(s[i])) {
        printf("\n\t\t\tRestart program and enter valid input!\n");
        sleep(3);
        system("clear");
        exit(0);
      }
   }
}

// data validation for numbers only input
void check_num(int x)
{
    if(x!=1) {
        printf("\n\t\t\tRestart program and enter valid input!\n");
        sleep(3);
        system("clear");
        exit(0);
      }
}

// function to validate length of GRC id
void check_id(char s[])
{
    if(strlen(s) != 10)
    {
        printf("\n\t\t\tRestart program and enter valid input!\n");
        sleep(3);
        system("clear");
        exit(0);
    }
}
