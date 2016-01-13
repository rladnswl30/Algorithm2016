/*
NQUEEN 알고스팟

https://www.algospot.com/judge/problem/read/NQUEEN

채점 성공

테스트 케이스
12
1 2 3 4 5 6 7 8 9 10 11 12
답:
1
0
0
2
10
4
40
92
352
724
2680
14200
*/
#include <iostream>

using namespace std;

inline void fillFlag(int N, bool(&flag)[12], bool(&diag)[23][2], int n, int level, bool val) {
	flag[n] = val;
	diag[n + level][0] = val;
	diag[N - 1 - n + level][1] = val;
}

int search(int N, bool(&flag)[12], bool(&diag)[23][2], int pre, int level, int res) {
	if (level == N) return res + 1;

	for (int n = 0; n < N; ++n) {
		if (flag[n] && (n != pre - 1) && (n != pre + 1) &&
			diag[n + level][0] && diag[N - 1 - n + level][1]) {
			fillFlag(N, flag, diag, n, level, false);
			res = search(N, flag, diag, n, level + 1, res);
			fillFlag(N, flag, diag, n, level, true);
		}
	}

	return res;
}

int main() {
	int C, N;
	bool flag[12], diag[23][2];

	cin >> C;

	fill(flag, flag + sizeof(flag), true);
	fill(&diag[0][0], &diag[0][0] + sizeof(diag), true);

	for (int c = 0; c < C; ++c) {
		cin >> N;
		cout << search(N, flag, diag, -2, 0, 0) << endl;
	}

	return 0;
}