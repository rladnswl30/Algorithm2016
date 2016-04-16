#include <stdio.h>

int main(void) {
	int x, y, w, h = 0;
	int result = 1000;

	scanf("%d %d %d %d", &x, &y, &w, &h);

	if (w - x < h - y) {
		result = w - x;
	}
	else if (w - x > h - y) {
		result = h - y;
	}

	if (result > x) {
		result = x;
	}
	if (result > y) {
		result = y;
	}

	printf("%d\n", result);
}