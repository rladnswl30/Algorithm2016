/* 2015.11.14
Ÿ�ϸ� �˰���
https://algospot.com/judge/problem/read/TILING2

ä�� ����

DP, �Ǻ���ġ

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

�� Ǯ�̹��� 

������ �̿��� Ǯ�̷� Combination ������ �ſ� ū �μ������� 
����� �������� �ʱ� ������ ���� �� �� ����. 

 �Ѥ�        ��
|�Ѥ�| 1)�� |  | 2) �� ������ �����µ�  1�� 2 �ΰ��� ǥ�� �� �� �ִ�.
 �Ѥ�        ��
 �̷� �� ���� Ȯ�� ����� ���ָ� �ȴ�.

�Ľ�Į �ﰢ���� �밢������ ���ϸ� �ᱹ �Ǻ���ġ ������ ���´�.
�̸� �����ϴ� ���� ����Ʈ :
http://mathworld.wolfram.com/PascalsTriangle.html
��������� Ʋ���� �ƴϰ� big integer�� 
������ �� �� ���� ������ ����


// ���װ�� Ǯ�̹�
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

		int r2 = n / 2;		// row 2 �� ¥��
		int c1 = n % 2;		// col 1 �� ¥��
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
�׽�Ʈ ���̽�
3
1
5
100
��:
1
8
782204094
*/