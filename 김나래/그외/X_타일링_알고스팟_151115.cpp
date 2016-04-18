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

inline unsigned long long mod(unsigned long long num) {
	return (num %REMAINDER) == 0 ? REMAINDER : (num %REMAINDER);
}

// unsigned long long  64 C 33 까지 가능한 combination source
unsigned long long gcd(unsigned long long x, unsigned long long y) {
	while (y != 0)
	{
		unsigned long long t = x % y;
		x = y;
		y = t;
	}
	return x;
}

unsigned long long Combination(unsigned long long n, unsigned long long k) {
	if (k > n)
		throw std::invalid_argument("invalid argument in choose");
	unsigned long long r = 1;
	for (unsigned long long d = 1; d <= k; ++d, --n)
	{
		unsigned long long g = gcd(r, d);
		r /= g;
		unsigned long long t = n / (d / g);
		if (r > std::numeric_limits<unsigned long long>::max() / t)
			throw std::overflow_error("overflow in choose");
		r *= t;
	}
	return r;
}

int main() {
	int C, i, j;
	cin >> C;

	unsigned long long* res = new unsigned long long[C];
	for (i = 0; i < C; ++i) {
		int n;
		cin >> n;

		int r2 = n / 2;		// row 2 개 짜리
		int c1 = n % 2;		// col 1 개 짜리
		res[i] = Combination(c1 + r2, c1 < r2 ? c1 : r2);

		int tmp = r2;
		for (j = 0; j< r2; ++j) {
			--tmp;
			c1 += 2;
			res[i] = res[i] + Combination(c1 + tmp, c1 < tmp ? c1 : tmp);
			res[i] = mod(res[i]);
		}
	}

	for (int i = 0; i < C; ++i)
		cout << res[i] << endl;

	return 0;
}