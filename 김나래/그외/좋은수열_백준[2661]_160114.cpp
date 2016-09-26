/*
좋은 수열 / 백준

https://www.acmicpc.net/problem/2661

채점 성공
깊이 우선 탐색 (재귀 풀이)
백 트래킹
-> 깊이우선탐색 일반 루프 관련 풀이 필요.
==> 함수 호출을 많이 해도 시간초과가 많이 날 수 있음.
*/
#include <iostream>
#include <string>

using namespace std;

string search(int N, string pre) {
	string res;
	if (pre.length() == N) return pre;

	for (int i = 0; i < 3; ++i) {
		bool isGood = true;
		if (i + 1 != (pre.back() - '0')) {
			string tmp = pre + to_string(i + 1);
			int len = tmp.length();
			for (int i = 1; i < len / 2; ++i) {
				if (tmp.substr(len - 2 * i - 2, i + 1).compare(
					tmp.substr(len - i - 1, i + 1)) == 0) {
					isGood = false;
				}
			}

			if (isGood) {
				if ((res = search(N, tmp)) != "")
					return res;
			}
		}
	}
	return "";
}

int main() {
	int N;

	cin >> N;

	cout << search(N, "1") << endl;
	return 0;
}