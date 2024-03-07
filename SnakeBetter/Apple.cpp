#include "Apple.h"

Apple::Apple(int width, int height) {
	w = width;
	h = height;
	x = rand() % w;
	y = rand() % h;
}

void Apple::SpawnApple() {
	srand(time(NULL));
	x = rand() % w;
	y = rand() % h;
}