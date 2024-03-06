#include"SetCursor.h"

void gotoxy()
{
    COORD coordinate;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
}