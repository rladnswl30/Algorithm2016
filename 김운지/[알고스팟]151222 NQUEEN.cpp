/*#include <stdio.h>
#include <math.h>

#define MAX_QUEEN 12

int N = 0;
int answer = 0;
int queen_position[MAX_QUEEN];

void init() {
	answer = 0;
}

bool available(int queen, int col) {
	for (int i = 0; i < queen; i++) {
		if (queen_position[i] == col)
			return false;

		if (queen - i == abs(col - queen_position[i]))
			return false;
	}
	return true;
}

void put(int queen, int col) {
	queen_position[queen] = col;
}

void solve(int queen) {
	if (queen == N) {
		answer++;
		return;
	}

	for (int i = 0; i < N; i++) { //i = col
		if (available(queen, i)) {
			put(queen, i);
			solve(queen+1);
		}
	}
}

int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		init();
		scanf("%d", &N);
		solve(0);
		printf("%d\n", answer);
	}

	return 0;
}*/

#include <stdio.h>
#include <math.h>

int plane[12];
int n = 0;
int cnt = 0;

void process(int y) {
	if (y == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		bool ok = true;
		for (int j = 0; j < y; j++) {
			if (plane[j] == i || abs(y - j) == abs(i - plane[j])) {
				ok = false;
				break;
			}
		}

		if (ok) {
			plane[y] = i;
			for (int y = 0; y < n; y++) {
				printf("%d ", plane[y]);
			}
			printf("\n");
			process(y + 1);
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);

	while (tc--) {
		scanf("%d", &n);
		cnt = 0;	//ÃÊ±âÈ­
		process(0);

		printf("%d\n", cnt);
	}

	return 0;
}