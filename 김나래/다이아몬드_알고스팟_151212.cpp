/*
다이아몬드
https://algospot.com/judge/problem/read/DIAMONDPATH
채점 성공

테스트 케이스

7 			diamond[1][0]
13			diamond[2][0]
22			diamond[3][0]
29			diamond[4][1]
33			diamond[5][1]
35			diamond[6][1]
41			diamond[7][0]
48			diamond[8][0]

39		diamond[0][0]
82		diamond[1][0]
176		diamond[2][1]
274		diamond[3][2]
345		diamond[4][2]
400		diamond[5][1]
496		diamond[6][1]
569		diamond[7][0]
664		diamond[8][0]

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
				if (j - 1 < 0) diamond[i][j] += diamond[i - 1][j];
				else if (j == size - 1) diamond[i][j] += diamond[i - 1][j - 1];
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