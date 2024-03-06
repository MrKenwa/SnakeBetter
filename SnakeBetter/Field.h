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
	Field(unsigned int, unsigned int);
	void Fill(Snake, Apple);
	void Show();
};


