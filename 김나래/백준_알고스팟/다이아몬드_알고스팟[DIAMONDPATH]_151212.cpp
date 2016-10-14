/*
다이아몬드
https://algospot.com/judge/problem/read/DIAMONDPATH
채점 성공

동적 계획법

테스트 케이스

7 			dia[1][0]
13			dia[2][0]
22			dia[3][0]
29			dia[4][1]
33			dia[5][1]
35			dia[6][1]
41			dia[7][0]
48			dia[8][0]

39		dia[0][0]
82		dia[1][0]
176		dia[2][1]
274		dia[3][2]
345		dia[4][2]
400		dia[5][1]
496		dia[6][1]
569		dia[7][0]
664		dia[8][0]

*/
#include <iostream>

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }

int path(int **dia, int N) {
	int size, i, j;
	for (i = 1; i < 2 * N - 1; ++i) {
		size = i < N ? i+1 : 2*N-i-1;
		for (j = 0; j < size; ++j) {
			if (i < N) {
				if (j - 1 < 0) dia[i][j] += dia[i-1][j];
				else if (j == size - 1) dia[i][j] += dia[i-1][j-1];
				else dia[i][j] += max(dia[i-1][j-1], dia[i-1][j]);
			} else
				dia[i][j] += max(dia[i-1][j], dia[i-1][j+1]);
		}
	}
	return dia[2*N - 2][0];
}

int main() {
	int T, N, res, size;
	int** dia;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> N;
		dia = new int*[2*N-1];
		for (int n = 0; n < 2 * N - 1; ++n) {
			dia[n] = new int[N];
			size = n < N ? n+1 : 2*N-n-1;
			for (int j = 0; j < size; ++j)
				cin >> dia[n][j];
		}

		res = path(dia, N);
		cout << res << endl;
	}

	return 0;
}