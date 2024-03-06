#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Snake.h"
#include "Point.h"

using namespace std;

class Field {
public:
	Field(unsigned int, unsigned int);
	void Fill(Snake, Point);
	void Show();
private:
	vector<vector<char>> field;
};


