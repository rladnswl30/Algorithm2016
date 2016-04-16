/* 2015.11.14
타일링 알고스팟
https://algospot.com/judge/problem/read/TILING2

채점 성공

DP, 피보나치

*/
#include <iostream>

using namespace std;

const int Remainder = 1000000007;

int main() {
	int T, n;
	long long dp[100];

	for (int i = 0; i < 100; ++i)
		dp[i] = 0;

	dp[0] = 1;
	dp[1] = 2;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> n;

		for (int i = 0; i < n; ++i) {
			if (dp[i] == 0)
				dp[i] = (dp[i - 1] + dp[i - 2]) % Remainder;
		}

		cout << dp[n - 1] << endl;
	}

	return 0;
}

/*

이 풀이법은 

조합을 이용한 풀이로 Combination 연산이 매우 큰 인수에서는 
제대로 동작하지 않기 때문에 답이 될 수 없다. 

 ㅡㅡ        ㅡ
|ㅡㅡ| 1)과 |  | 2) 두 가지로 나뉘는데  1는 2 두개로 표현 될 수 있다.
 ㅡㅡ        ㅡ
 이런 걸 통해 확률 계산을 해주면 된다.

파스칼 삼각형을 대각선으로 더하면 결국 피보나치 수열이 나온다.
이를 증명하는 관련 사이트 :
http://mathworld.wolfram.com/PascalsTriangle.html
방법적으로 틀린게 아니고 big integer를 
구현해 낼 수 없기 때문에 실패


// 이항계수 풀이법
const unsigned long REMAINDER = 1000000007;

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
*/

/*
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