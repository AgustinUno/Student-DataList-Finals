// BSIT 1-2
// headers/ preprocessors
//Problem #2 Finals

#include <TOOLBOX.h>
// global/ external declarations
char studentID[20];
char studentName[20];

//To compare in duplicates
char stdID[20];
char stdName[20];

int z;

void scrn_2()
{
    system("cls");
    line1(10, 5, 65, 30+z);
}
void scrn_1()
{
    line1(10, 5, 65, 30);
    gotoxy(30, 15);
    printf("A] Data Entry\n");
    gotoxy(30, 16);
    printf("B] View\n");
    gotoxy(30, 17);
    printf("C] Close\n");
    gotoxy(29, 21);
    printf("Select an option: ");
}

void entry()
{
    system("cls");
    line1(10, 5, 65, 30);

    int x, y;
    gotoxy(30, 17);
    printf("Student Name: ");
    gotoxy(30, 15);
    printf("Student ID: ");
    gotoxy(32, 16);
    scanf("%s", studentID);

    gotoxy(32, 18);
    scanf("%s", studentName);

    FILE *file;
    file = fopen("StudList.txt", "r");

    int exists = 0;
		//checks duplicates in the text file
    while (fscanf(file, "%s %s", stdID, stdName) != EOF)
    {

        if (strcmp(stdID, studentID) == 0)
        {
            exists = 1;
            break;
        }
    }

    FILE *Add = fopen("StudList.txt", "a");
    if (exists)
    {
        
        gotoxy(21, 25);
        printf("Word already exists in the file.");
        gotoxy(24, 26);
        printf("Press any key to continue...");
    }
    else
    {
        fprintf(Add, "%s %s\n", studentID, studentName);
        gotoxy(23, 25);
        printf("Student added to the file.\n");
        gotoxy(24, 26);
        printf("Press any key to continue...");
    }

    // Close the file
    fclose(file);
    fclose(Add);

    getch();
    system("cls");
    scrn_1();
}

void view()
{
    system("cls");
  
    	//reads text file
    FILE *read = fopen("StudList.txt", "r");
    line1(10, 5, 65, 30+z);
    gotoxy(23, 10);
    printf("Student ID");
    gotoxy(40, 10);
    printf("Student name");line1(10, 5, 65, 30+z);
    while (fscanf(read, "%s %s", stdID, stdName) != EOF)
    {
        gotoxy(23, 12 + z);
        printf("%s", stdID);
        gotoxy(40, 12 + z);
        printf("%s", stdName);
        z++;
    }
    fclose(read);
    
    gotoxy(24, 15 +z);
    printf("Press any key to continue...");
    getch();

    system("cls");
    scrn_1();
}
main()
{
    // this is the main function

    scrn_1();
    char option;

    while (1)
    {
        gotoxy(48, 21);
        option = getche();

        switch (tolower(option))
        {

        case 'a':
            entry();

            break;
        case 'b':
            view();
            break;
        case 'c':
            return 0;
            break;

        default:
            gotoxy(22, 25);
            printf("Invalid option. Please try again.");
            break;
        }
    }
}
