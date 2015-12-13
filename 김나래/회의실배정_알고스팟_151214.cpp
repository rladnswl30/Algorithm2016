/*
회의실 배정
https://www.acmicpc.net/problem/1931
채점 성공

테스트 케이스
6
1 1
1 2
2 2
3 3
2 3
4 4
답: 6

6
1 1
1 2
2 2
2 3
3 3
4 4
답: 6
*/

#include <iostream>

using namespace std;

int main() {
	int N, cnt = 1;
	cin >> N;

	pair<int, int> *arr = new pair<int, int>[N];
	for (int i = 0; i < N; ++i) {
		pair<int, int> p;
		cin >> p.first >> p.second;
		arr[i] = p;
	}

	qsort(arr, N, sizeof(pair<int, int>), [](const void* a, const void* b) {
		pair<int, int> arg1 = *(static_cast<const pair<int, int>*>(a));
		pair<int, int> arg2 = *(static_cast<const pair<int, int>*>(b));

		if (arg1.second < arg2.second) return -1;
		if (arg1.second > arg2.second) return 1;
		if (arg1.first == arg1.second) return 1;
		if (arg2.first == arg2.second) return -1;
	});

	pair<int, int> pre = arr[0];
	for (int i = 1; i < N; ++i) {
		if (arr[i].first >= pre.second) {
			cnt++;
			pre = arr[i];
		}
	}

	if (N == 0) cout << "0" << endl;
	else cout << cnt << endl;

	return 0;
}