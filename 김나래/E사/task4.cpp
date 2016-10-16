/*
시간 복잡도 .. : ??
공간복잡도 O(1)

==> 시간 복잡도 O(1) 안에 풀 수 있어야함
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;
enum direction { L, R, U, D };

void nextDirect(int &d) {
	switch (d) {
	case U:
		d = R;
		break;
	case D:
		d = L;
		break;
	case L:
		d = U;
		break;
	case R:
		d = D;
		break;
	}
}


int solution(int X, int Y) {
	int x = 0, y = 0;
	int cnt = 0;
	int num = 0;
	int direct = U;

	while (1) {
		++cnt;
		for (int j = 0; j < 2; ++j) {
			for (int i = 0; i < cnt; ++i) {
				++num;
				switch (direct) {
				case U:
					++y; break;
				case D:
					--y; break;
				case R:
					++x; break;
				case L:
					--x; break;
				}

				if (x == X && y == Y) {
					return num;
				}

			}
			nextDirect(direct);
		}
	}
	return -1;
}


int main() {
	int X, Y;

	cin >> X >> Y;
	int res = solution(X, Y);
	cout << res << endl;

	return 0;
}