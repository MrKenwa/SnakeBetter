#pragma once
#include "Point.h"
#include <ctime>
#include <iostream>

class Apple {
public:
	Point SpawnApple(int, int);
private:
	int x, y;
};