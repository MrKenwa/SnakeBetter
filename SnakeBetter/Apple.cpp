#include "Apple.h"

Point Apple::SpawnApple(int w, int h) {
	srand(time(NULL));
	int x = rand() % (w + 1);
	int y = rand() % (h + 1);
	Point p { x, y };
	return p;
}