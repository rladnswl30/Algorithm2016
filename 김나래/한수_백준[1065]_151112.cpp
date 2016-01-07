/*
한수
https://www.acmicpc.net/problem/1065

채점성공

테스트 케이스
110
답 : 99

135
답 : 102
*/
#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	if (N < 100) {
		cout << N << endl;
		return 0;
	}

	int cnt = 99, i = 100;
	while (i < N + 1) {

		int n = i, d, pre;
		bool first = true, isSeq = true;
		while (n > 0) {
			if (first) {
				pre = n % 10;
				d = ((n / 10) % 10) - pre;
				first = false;
			}
			else {
				if ((n % 10) - pre != d) isSeq = false;
				pre = n % 10;
			}
			n /= 10;
		}
		if (isSeq)
			++cnt;
		++i;
	}

	cout << cnt << endl;

	return 0;
}