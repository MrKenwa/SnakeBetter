#include"Snake.h"

using namespace std;

Snake::Snake(Point startPoint) {
	body = { startPoint };
	len = 1;
	dir = 0;
}

void Snake::MoveSnake(bool flag) {
	if (flag) {
		ChangeDirection();
	}
	if (dir == Consts::UP) {
		body[0].y--;
	}
	else if (dir == Consts::DOWN) {
		body[0].y++;
	}
	else if (dir == Consts::LEFT) {
		body[0].x--;
	}
	else if (dir == Consts::RIGHT) {
		body[0].x++;
	}
}

void Snake::ChangeDirection() {
	int key;
	key = _getch();
	//rewind(stdin);
	while (_kbhit()) {
		_getch();
	}
	if (key == 119 && dir != Consts::DOWN) {
		dir = Consts::UP;
	}
	else if (key == 115 && dir != Consts::UP) {
		dir = Consts::DOWN;
	}
	else if (key == 97 && dir != Consts::RIGHT) {
		dir = Consts::LEFT;
	}
	else if (key == 100 && dir != Consts::LEFT) {
		dir = Consts::RIGHT;
	}

}
