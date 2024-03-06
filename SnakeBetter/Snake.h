#pragma once
#include<iostream>
#include<vector>
#include<conio.h>
#include"Point.h"
#include"Consts.h"
#include"Apple.h"

using namespace std;

class Apple;

class Snake {
public:
	int len;
	int dir;
	vector<Point> body;
	Snake(Point);

	bool MoveSnake(bool, Apple);

	void ChangeDirection();

	bool isEat(Apple);

	bool increaseSnake(Apple);

};
