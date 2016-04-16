/*
3차원 토마토 백준
https://www.acmicpc.net/problem/7569

넓이 우선탐색

채점 성공
*/

#include <iostream>
#include <queue>

using namespace std;

typedef struct Triple {
	int h, n, m;
	Triple(int _h, int _n, int _m) :h(_h), n(_n), m(_m) {}
	Triple() {}
}Triple;

void ripeTomato(int***& box, queue<Triple>& que, int h, int n, int m) {
	box[h][n][m] = 1;
	que.push(Triple(h, n, m));
}

int grow(int***& box, queue<Triple>& que, int H, int N, int M, int t) {
	int res = 0, cnt = 0;

	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i< size; ++i, ++cnt) {
			int h = que.front().h;
			int n = que.front().n;
			int m = que.front().m;

			if ((n + 1 < N) && (box[h][n + 1][m] == 0))
				ripeTomato(box, que, h, n + 1, m);
			if ((n - 1 >= 0) && (box[h][n - 1][m] == 0))
				ripeTomato(box, que, h, n - 1, m);

			if ((m + 1 < M) && (box[h][n][m + 1] == 0))
				ripeTomato(box, que, h, n, m + 1);
			if ((m - 1 >= 0) && (box[h][n][m - 1] == 0))
				ripeTomato(box, que, h, n, m - 1);

			if ((h + 1 < H) && (box[h + 1][n][m] == 0))
				ripeTomato(box, que, h + 1, n, m);
			if ((h - 1 >= 0) && (box[h - 1][n][m] == 0))
				ripeTomato(box, que, h - 1, n, m);

			que.pop();
		}
		res++;
	}
	if ((res == 1) || (cnt < (H*N*M - t))) return -1;
	else return res - 1;
}

int main() {

	queue<Triple> que;
	int N, M, H, days = 0, cnt = 0;
	cin >> M >> N >> H;

	int ***box = new int**[H];

	for (int h = 0; h < H; ++h) {
		box[h] = new int*[N];
		for (int n = 0; n < N; ++n) {
			box[h][n] = new int[M];
			for (int m = 0; m < M; ++m) {
				cin >> box[h][n][m];
				if (box[h][n][m] == 1)
					que.push(Triple(h, n, m));
				else if (box[h][n][m] == -1)
					cnt++;
			}
		}
	}

	if (que.size() == H*N*M - cnt) days = 0;
	else
		days = grow(box, que, H, N, M, cnt);

	cout << days << endl;

	return 0;
}
/*
테스트 케이스
6 4 2
-1 -1 0 0 0 0
-1 -1 0 0 0 0
-1 -1 0 0 0 0
-1 -1 0 0 0 1
-1 -1 0 0 0 0
-1 -1 0 1 0 0
-1 -1 0 0 0 0
-1 -1 0 0 0 0
답 : 6

6 4 2
-1 -1 1 1 1 1
-1 -1 1 1 1 1
-1 -1 1 1 1 1
-1 -1 1 1 1 1
-1 -1 1 1 1 1
-1 -1 1 1 1 1
-1 -1 1 1 1 1
-1 -1 1 1 1 1
답 : 0
*/