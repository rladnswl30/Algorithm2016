/*
https://www.acmicpc.net/problem/1010
다리 놓기
채점 성공
*/
#include <iostream>

using namespace std;

unsigned long long Combination(int n, int k) {
	unsigned long long a = 1, r = 1;
	int i, j;

	for (i = n, j = 1; i >n - k; --i, j++) {
		a *= i;
		r *= j;
	}
	return a / r;
}

int main() {
	int T;
	cin >> T;
	unsigned long long *res = new unsigned long long[T];
	for (int i = 0; i<T; ++i) {
		int N, M;
		cin >> N >> M;

		if (N == M) res[i] = 1;
		else if (N == 1) res[i] = M;
		else res[i] = Combination(M, N > M - N ? M - N : N);
	}

	for (int i = 0; i< T; ++i)
		cout << res[i] << endl;

	return 0;
}