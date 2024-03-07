#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Snake.h"
#include "Point.h"
#include "Apple.h"

using namespace std;

class Snake;
class Apple;

class Field {
public:
	vector<vector<char>> field;
	Field(size_t, size_t);
	void Fill(Snake, Apple);
	void Show();
	bool isGameGoing(Snake);
private:
	size_t width, height;
};


