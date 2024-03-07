#include "Apple.h"

Apple::Apple(int width, int height) {
	w = width;
	h = height;
}

void Apple::SpawnApple() {
	srand(time(NULL));
	x = rand() % w;
	y = rand() % h;
}