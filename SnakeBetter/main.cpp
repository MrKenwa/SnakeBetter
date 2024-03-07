#include<iostream>
#include<vector>
#include<Windows.h>
#include <stdlib.h>
#include"Field.h"
#include"Point.h"
#include"Snake.h"
#include"Apple.h"
#include"SetCursor.h"

using namespace std;

//void init() {
//	HANDLE stdh = GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_SCREEN_BUFFER_INFO csbi;
//	GetConsoleScreenBufferInfo(stdh, &csbi);
//	int board_size_x = csbi.srWindow.Right - csbi.srWindow.Left + 1;
//	int board_size_y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
//	std::cout << board_size_x << " " << board_size_y;
//}

int main() {
	// Set cursor position and hiding cursor
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(consoleHandle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &structCursorInfo);

	// Field width and height
	size_t w = 30;
	size_t h = 20;

	// Snakes head position
	Point startPoint = { w / 2, h / 2 };
	Snake snake(startPoint);

	// Initialization of apple
	Apple eda(w, h);
	eda.SpawnApple();

	// Init field
	Field map(w, h);

	bool gameGoing = true;
	while (gameGoing) {
		bool isHit = false;
		isHit = _kbhit();

		bool isEated = snake.MoveSnake(isHit, eda);
		if (isEated) {
			eda.SpawnApple();
			while (map.field[eda.y][eda.y] == '@') {
				eda.SpawnApple();
			}
		}

		gameGoing = map.isGameGoing(snake);

		if (gameGoing) {
			map.Fill(snake, eda);
			map.Show();
			Sleep(100);
		}

		gotoxy();
	}
	system("cls");
	cout << "You loooooose!1!!11!!" << endl;
}