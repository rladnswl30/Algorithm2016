/*
토마토 백준
https://www.acmicpc.net/problem/7576

넓이 우선탐색

채점 성공
*/

#include <iostream>
#include <queue>

using namespace std;

typedef struct Tuple {
	int x, y;
	Tuple(int _x, int _y) :x(_x), y(_y) {}
	Tuple() {}
}Tuple;

void ripeTomato(int** box, queue<Tuple>& que, int n, int m) {
	box[n][m] = 1;
	que.push(Tuple(m, n));
}

int grow(int** box, queue<Tuple> que, int N, int M, int t) {
	int res = 0, cnt = 0;

	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i< size; ++i, ++cnt) {
			int n = que.front().y;
			int m = que.front().x;

			if ((n + 1 < N) && (box[n + 1][m] == 0))
				ripeTomato(box, que, n + 1, m);

			if ((n - 1 >= 0) && (box[n - 1][m] == 0))
				ripeTomato(box, que, n - 1, m);

			if ((m + 1 < M) && (box[n][m + 1] == 0))
				ripeTomato(box, que, n, m + 1);

			if ((m - 1 >= 0) && (box[n][m - 1] == 0))
				ripeTomato(box, que, n, m - 1);

			que.pop();
		}
		res++;
	}
	if ((res == 1) || (cnt < (N*M - t))) return -1;
	else return res - 1;
}

int main() {

	queue<Tuple> que;
	int N, M, days = 0, cnt = 0;
	cin >> M >> N;

	int **box = new int*[N];

	for (int n = 0; n < N; ++n)
		box[n] = new int[M];

	for (int n = 0; n < N; ++n) {
		for (int m = 0; m < M; ++m) {
			cin >> box[n][m];
			if (box[n][m] == 1)
				que.push(Tuple(m, n));
			else if (box[n][m] == -1)
				cnt++;
		}
	}
	if (que.size() == N*M - cnt) days = 0;
	else
		days = grow(box, que, N, M, cnt);

	cout << days << endl;

	return 0;
}
/*
테스트 케이스
6 4
-1 -1 0 0 0 0
-1 -1 0 0 0 0
-1 -1 0 0 0 0
-1 -1 0 0 0 1
답 : 6

6 4
0 0 -1 0 0 0
0 -1 0 -1 0 0
0 0 -1 0 0 0
0 0 0 0 0 1
답: -1

6 4
0 -1 1 1 1 1
0 -1 1 1 1 1
0 -1 1 1 1 1
0 -1 1 1 1 1
답 : -1

6 4
0 -1 0 0 0 0
0 -1 0 0 0 0
0 -1 0 0 0 0
0 -1 0 0 0 1
답 : -1

6 4
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
답 : -1

6 4
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
답 : 0

6 4
-1 -1 1 1 1 1
-1 -1 1 1 1 1
-1 -1 1 1 1 1
-1 -1 1 1 1 1
답 : 0
*/