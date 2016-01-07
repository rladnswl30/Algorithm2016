/* 2015.11.14
타일링 알고스팟
https://algospot.com/judge/problem/read/TILING2

-> 본래 동적 계획법으로 풀어야 함.

테스트 케이스
3
1
5
100
답:
1
8
782204094
*/
#include <iostream>

using namespace std;

const unsigned long REMAINDER = 1000000007;

unsigned long long Combination(int n, int k) {
	unsigned long long a = 1, r = 1;
	int i, j;

	for (i = n, j = 1; i >n - k; --i, j++) {
		a *= i;
		r *= j;
	}
	return (a / r) % REMAINDER;
}

int main() {
	int C, i;
	cin >> C;

	unsigned long long* res = new unsigned long long[C];
	for (i = 0; i < C; ++i) {
		int n;
		cin >> n;

		int r2 = n / 2;		// row 2 개 짜리
		int c1 = n % 2;		// col 1 개 짜리
		res[i] = Combination(c1 + r2, c1 < r2 ? c1 : r2);

		int tmp = r2;
		for (int j = 0; j< r2; ++j) {
			--tmp;
			c1 += 2;
			res[i] = res[i] % REMAINDER + Combination(c1 + tmp, c1 < tmp ? c1 : tmp);
			res[i] %= REMAINDER;
		}
	}

	for (int i = 0; i < C; ++i)
		cout << res[i] << endl;

	return 0;
}