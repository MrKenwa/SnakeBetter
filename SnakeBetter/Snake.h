#pragma once
#include<iostream>
#include<vector>
#include<conio.h>
#include"Point.h"
#include"Consts.h"

using namespace std;

class Snake {
public:
	int len;
	int dir;
	vector<Point> body;
	Snake(Point);

	void MoveSnake(bool);

	void ChangeDirection();

	void isEat();

};
