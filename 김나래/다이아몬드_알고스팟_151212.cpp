/*
다이아몬드
https://algospot.com/judge/problem/read/DIAMONDPATH

*/
#include <iostream>

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }

int path(int **diamond, int N) {
	int size, i, j;
	for (i = 1; i < 2 * N - 1; ++i) {
		size = i < N ? i + 1 : (2 * N - i - 1);
		for (j = 0; j < size; ++j) {
			if (i < N) {
				if (j - 1 < 0) diamond[i][j] += max(diamond[i - 1][j], 0);
				else if (j == size - 1) diamond[i][j] += max(diamond[i - 1][j - 1], 0);
				else diamond[i][j] += max(diamond[i - 1][j - 1], diamond[i - 1][j]);
			}
			else
				diamond[i][j] += max(diamond[i - 1][j], diamond[i - 1][j + 1]);
		}
	}
	return diamond[2 * N - 2][0];
}

int main() {
	int T, N, res, size, n, t;
	int** diamond;
	cin >> T;
	for (t = 0; t < T; ++t) {
		cin >> N;
		diamond = new int*[2 * N - 1];
		for (n = 0; n < 2 * N - 1; ++n) {
			diamond[n] = new int[N];
			size = n < N ? n + 1 : 2 * N - n - 1;
			for (int j = 0; j < size; ++j)
				cin >> diamond[n][j];
		}

		res = path(diamond, N);
		cout << res << endl;
	}

	return 0;
}