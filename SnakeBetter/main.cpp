#include<iostream>
#include<vector>
#include<Windows.h>
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
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(consoleHandle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &structCursorInfo);

	unsigned int w = 30;
	unsigned int h = 20;

	Point startPoint = { w / 2, h / 2 };
	Snake snake(startPoint);

	Apple eda(w, h);
	eda.SpawnApple();

	Field map(h, w);

	bool flag = true;
	while (flag) {
		bool isHit = false;
		isHit = _kbhit();

		//snake.MoveSnake(isHit, eda);
		bool isEated = snake.MoveSnake(isHit, eda);
		//bool isEated = snake.isEat(eda);
		if (isEated) {
			eda.SpawnApple();
			while (map.field[eda.y][eda.y] == '@') {
				eda.SpawnApple();
			}
		}
		map.Fill(snake, eda);
		map.Show();
		Sleep(100);
		gotoxy();
	}

}