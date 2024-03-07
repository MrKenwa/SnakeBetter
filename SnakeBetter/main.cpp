#include <iostream>
#include <vector>
#include <Windows.h>
#include <stdlib.h>
#include <fstream>
#include "Field.h"
#include "Point.h"
#include "Snake.h"
#include "Apple.h"
#include "SetCursor.h"
#include "Record.h"

using namespace std;

//void init() {
//	HANDLE stdh = GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_SCREEN_BUFFER_INFO csbi;
//	GetConsoleScreenBufferInfo(stdh, &csbi);
//	int board_size_x = csbi.srWindow.Right - csbi.srWindow.Left + 1;
//	int board_size_y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
//	std::cout << board_size_x << " " << board_size_y;
//}

bool doYouWannaPlay() {
	while (!_kbhit()) {
		continue;
	}
	if (_kbhit()) {
		return true;
	}
	return false;
}

int main() {
	// Set cursor position and hiding cursor
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(consoleHandle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &structCursorInfo);

	cout << "WELCOME TO THE SNAKE'S LAIR!" << endl;
	cout << "PRESS ANY KEY TO START THE GAME..." << endl;
	bool startGame = doYouWannaPlay();
	system("cls");
	while (startGame) {
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

		// Record init
		Record record;

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
				gotoxy();
			}
			else {
				startGame = false;
				record.SetRecord(snake.len);
				system("cls");
				cout << "YOU LOOOOSE!" << endl;
				cout << "YOUR RECORD: " << record.GetRecord() << endl;
				cout << "PRESS ANY KEY TO RESTART GAME..." << endl;
				startGame = doYouWannaPlay();
				system("cls");
			}
		}
	}
	
}