#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
typedef enum {
    COLOR_BLACK,
    COLOR_RED,
    COLOR_GREEN,
    COLOR_YELLOW,
    COLOR_BLUE,
    COLOR_MAGENTA,
    COLOR_CYAN,
    COLOR_WHITE
} Color;


void gotoxy(int x, int y)
{
        HANDLE col = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD row;
        row.X = x;
        row.Y = y;
        SetConsoleCursorPosition(col, row);
}
void box(int x1, int y1, int x2, int y2, char ch)
{ // creates a border using a specified ascii char
        int x;
        for (x = x1; x <= x2; x++)
        {
                gotoxy(x, y1);
                putchar(ch);
                gotoxy(x, y2);
                putchar(ch);
        }
        for (x = y1; x <= y2; x++)
        {
                gotoxy(x1, x);
                putchar(ch);
                gotoxy(x2, x);
                putchar(ch);
        }
}
void fillscreen(int x1, int y1, int x2, int y2, char ch)
{ // fills the screen with an ascii char
        int col, row;
        for (col = x1; col <= x2; col++)
        {
                for (row = y1; row <= y2; row++)
                {
                        gotoxy(col, row);
                        putchar(ch);
                }
        }
}
void clearportion(int x1, int y1, int x2, int y2)
{ // creates an opening or clears a portion of a screen
        int col, row;
        for (col = x1; col <= x2; col++)
        {
                for (row = y1; row <= y2; row++)
                {
                        gotoxy(col, row);
                        putchar(' ');
                }
        }
}
void printxy(int col, int row, char ch[])
{ // function to replace gotoxy and printf
        gotoxy(col, row);
        puts(ch);
}
void center(int row, char ch[])
{ // function that displays a text at the center of the screen
        int col = (80 - strlen(ch)) / 2 + 1;
        gotoxy(col, row);
        puts(ch);
}
void hline(int row, int col1, int col2, char ch)
{ // creates a horizontal line
        int x;
        for (x = col1; x <= col2; x++)
        {
                gotoxy(x, row);
                putchar(ch);
        }
}
void vline(int col, int row1, int row2, char ch)
{ // creates a vertical line
        int x;
        for (x = row1; x <= row2; x++)
        {
                gotoxy(col, x);
                putchar(ch);
        }
}
void eraserow(int row, int col1, int col2)
{ // clears a particular row in a screen
        int x;
        for (x = col1; x <= col2; x++)

        {
                gotoxy(x, row);
                printf(" ");
        }
}
void line2(int col1, int row1, int col2, int row2)
{ // creates a double line border
        int x;
        for (x = col1; x <= col2; x++)
        {
                gotoxy(x, row1);
                printf("%c", 205);
                gotoxy(x, row2);
                printf("%c", 205);
        }
        for (x = row1; x <= row2; x++)
        {
                gotoxy(col1, x);
                printf("%c", 186);
                gotoxy(col2, x);
                printf("%c", 186);
        }
        gotoxy(col1, row1);
        putchar(201);
        gotoxy(col2, row1);
        putchar(187);
        gotoxy(col1, row2);
        putchar(200);
        gotoxy(col2, row2);
        putchar(188);
}
void line1(int col1, int row1, int col2, int row2)
{ // creates a single line border
        int x;
        for (x = col1; x <= col2; x++)
        {
                gotoxy(x, row1);
                putchar(196);
                gotoxy(x, row2);
                putchar(196);
        }
        for (x = row1; x <= row2; x++)
        {
                gotoxy(col1, x);
                putchar(179);
                gotoxy(col2, x);
                putchar(179);
        }
        gotoxy(col1, row1);
        putchar(218);
        gotoxy(col2, row1);
        putchar(191);
        gotoxy(col1, row2);
        putchar(192);
        gotoxy(col2, row2);
        putchar(217);
}
void scanxy(int x, int y, char z[]){
	
	gotoxy(x, y);
	scanf("%s", z);
	
}


// Function to set the console text color
void SetConsoleTextColor(Color color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD attributes = FOREGROUND_INTENSITY;
    
    switch (color) {
        case COLOR_BLACK:
            attributes |= 0;
            break;
        case COLOR_RED:
            attributes |= FOREGROUND_RED;
            break;
        case COLOR_GREEN:
            attributes |= FOREGROUND_GREEN;
            break;
        case COLOR_YELLOW:
            attributes |= FOREGROUND_RED | FOREGROUND_GREEN;
            break;
        case COLOR_BLUE:
            attributes |= FOREGROUND_BLUE;
            break;
        case COLOR_MAGENTA:
            attributes |= FOREGROUND_RED | FOREGROUND_BLUE;
            break;
        case COLOR_CYAN:
            attributes |= FOREGROUND_GREEN | FOREGROUND_BLUE;
            break;
        case COLOR_WHITE:
            attributes |= FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
            break;
        default:
            break;
    }
    
    SetConsoleTextAttribute(hConsole, attributes);
}

// Function to print colored text
void ColoredText(Color color, const char* text) {
    SetConsoleTextColor(color);
    printf("%s", text);
    SetConsoleTextColor(COLOR_WHITE); // Resetting the color to white (default)
}

void pushColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void adjustWidth(char* str, int width) {
    int len = strlen(str);
    if (len < width) {
        int spaces = width - len;
        for (int i = 0; i < spaces; i++) {
            strcat(str, " ");
        }
    }
}
