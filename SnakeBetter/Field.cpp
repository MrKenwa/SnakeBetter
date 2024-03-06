#include "Field.h"

using namespace std;

Field::Field(unsigned int width, unsigned int height) {
	//vector<vector<char>> field(width, vector<char>(height));
	field = { width, vector<char>(height) };
}

void Field::Fill(Snake snake, Point apple) {
	size_t height = field.size();
	size_t width = field[0].size();

	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			field[i][j] = ' ';
		}
	}

	for (size_t i = 0; i < snake.len; ++i) {
		field[snake.body[i].y][snake.body[i].x] = '@';
	}

	field[apple.y][apple.x] = '*';
}

void Field::Show() {
	size_t height = field.size();
	size_t width = field[0].size();

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