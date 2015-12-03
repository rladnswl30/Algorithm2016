#include <iostream>
#include <deque>

using namespace std;

typedef struct Tuple {
	int x, y;
	Tuple(int _x, int _y) :x(_x), y(_y) {}
	Tuple() {}
}Tuple;

int grow(int res, deque<Tuple> que, int** box, int N, int M) {
	deque<Tuple> tmp;
	if (que.empty()) return res - 1;

	while (!que.empty()) {
		int n = que.front().x;
		int m = que.front().y;

		if ((n + 1 < N) && (box[n + 1][m] == 0)) {
			box[n + 1][m] = 1;
			tmp.push_back(Tuple(n + 1, m));
		}
		if ((n - 1 >= 0) && (box[n - 1][m] == 0)) {
			box[n - 1][m] = 1;
			tmp.push_back(Tuple(n - 1, m));
		}
		if ((m + 1 < M) && (box[n][m + 1] == 0)) {
			box[n][m + 1] = 1;
			tmp.push_back(Tuple(n, m + 1));
		}
		if ((m - 1 >= 0) && (box[n][m - 1] == 0)) {
			box[n][m - 1] = 1;
			tmp.push_back(Tuple(n, m - 1));
		}

		que.pop_front();
	}
	que.shrink_to_fit();
	return grow(++res, tmp, box, N, M);
}

int main() {

	deque<Tuple> que;
	int N, M, days = 0;
	cin >> M >> N;
	int **box = new int*[N];

	for (int n = 0; n < N; ++n)
		box[n] = new int[M];

	for (int n = 0; n < N; ++n)
		for (int m = 0; m < M; ++m) {
			cin >> box[n][m];
			if (box[n][m] == 1)
				que.push_back(Tuple(n, m));
		}

	days = grow(0, que, box, N, M);

	cout << days << endl;

	return 0;
}