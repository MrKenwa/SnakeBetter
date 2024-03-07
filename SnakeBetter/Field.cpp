#include "Field.h"

using namespace std;

Field::Field(size_t fieldWidth, size_t fieldHeight) {
	width = fieldWidth;
	height = fieldHeight;
	field = { height, vector<char>(width) };
}

void Field::Fill(Snake snake, Apple apple) {
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			field[i][j] = ' ';
		}
	}

	field[apple.y][apple.x] = '*';

	for (size_t i = 0; i < snake.len; ++i) {
		field[snake.body[i].y][snake.body[i].x] = '@';
	}
}

void Field::Show() {
	for (size_t i = 0; i < width + 2; i++) {
		cout << '#';
	}
	cout << '\n';

	for (size_t i = 0; i < height; ++i) {
		cout << "#";
		for (size_t j = 0; j < width; ++j) {
			cout << field[i][j];
		}
		cout << "#" << '\n';
	}

	for (size_t i = 0; i < width + 2; i++) {
		cout << '#';
	}
}

bool Field::isGameGoing(Snake snake) {
	bool flag = true;
	for (size_t i = 1; i != snake.len; ++i) {
		if (snake.body[0].x == snake.body[i].x &&
			snake.body[0].y == snake.body[i].y) {
			flag = false;
		}
	}

	if (snake.body[0].x >= width ||
		snake.body[0].x < 0 ||
		snake.body[0].y >= height ||
		snake.body[0].y < 0) {
		flag = false;
	}

	return flag;
}