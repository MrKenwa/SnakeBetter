#include"Snake.h"

using namespace std;

Snake::Snake(Point startPoint) {
	body = { startPoint, {startPoint.x, startPoint.y + 1} };
	len = 2;
	dir = 0;
}

bool Snake::MoveSnake(bool flag, Apple apple) {
	if (flag) {
		ChangeDirection();
	}
	bool eat = increaseSnake(apple);
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
	return eat;
}

void Snake::ChangeDirection() {
	int key;
	key = _getch();
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

bool Snake::isEat(Apple a) {
	if (a.x == body[0].x && a.y == body[0].y) {
		return true;
	}
	else {
		return false;
	}
}

bool Snake::increaseSnake(Apple a) {
	bool flag = isEat(a);
	if (flag) {
		body.push_back(body[len - 1]);
		len++;		
	}
	for (size_t i = len - 1; i > 0; --i) {
		body[i] = body[i - 1];
	}
	return flag;
}