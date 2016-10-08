/*
유기농 배추
https://www.acmicpc.net/problem/1012

깊이 우선 탐색

채점 성공

*/

#include <iostream>

using namespace std;

void Check(int(&G)[50][50], const int &N, const int &M, int i, int j) {
	G[i][j] = 0;
	if (i - 1 >= 0 && G[i - 1][j] == 1) Check(G, N, M, i - 1, j);
	if (j + 1 < M  && G[i][j + 1] == 1) Check(G, N, M, i, j + 1);
	if (i + 1 < N  && G[i + 1][j] == 1) Check(G, N, M, i + 1, j);
	if (j - 1 >= 0 && G[i][j - 1] == 1) Check(G, N, M, i, j - 1);
}
int main() {

	int G[50][50], T;

	cin >> T;
	for (int t = 0; t < T; ++t) {
		int M, N, K, count = 0;
		cin >> M >> N >> K;

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				G[i][j] = 0;

		for (int k = 0; k < K; ++k) {
			int x, y;
			cin >> x >> y;
			G[y][x] = 1;
		}

		for (int i = 0; i < N; ++i)
			for (int j = 0; j<M; ++j)
				if (G[i][j] == 1) {
					Check(G, N, M, i, j);
					count++;
				}

		cout << count << endl;
	}
}

/*
테스트 케이스
입력 :
2
10 8 17
0 0
1 0
1 1
4 2
4 3
4 5
2 4
3 4
7 4
8 4
9 4
7 5
8 5
9 5
7 6
8 6
9 6
10 10 1
5 5

답:
5
1
*/