#pragma once
#include "Point.h"
#include <ctime>
#include <iostream>
#include <vector>
#include "Field.h"

class Apple {
public:
	Apple(int, int);
	int x, y, w, h;
	void SpawnApple();
};