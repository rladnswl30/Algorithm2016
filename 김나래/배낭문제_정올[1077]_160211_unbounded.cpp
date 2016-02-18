/*
정올
배낭 채우기
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=357&sca=3050

채점 성공
그리디
unbounded knnapspack

테스트 케이스
4 14
2 40
5 110
10 200
3 50
답 : 300
*/

#include <iostream>

using namespace std;

int UnboundedKnapspack(pair<int, int>(&p)[1000], int N, int weight) {

	//무게당 값어치의 비중이 큰 순서대로 정렬
	qsort(p, N, sizeof(pair<int, int>), [](const void* l, const void* r) {
		pair<int, int> lc = *static_cast<const pair<int, int> *>(l);
		pair<int, int> rc = *static_cast<const pair<int, int> *>(r);
		if ((lc.second / lc.first) < (rc.second / rc.first)) return 1;
		return -1;
	});

	int maxValue = 0, i = 0;

	while (weight != 0 && i < N) {
		if (weight < p[i].first) {
			++i;
			continue;
		}

		int cnt = weight / p[i].first;
		maxValue += (p[i].second*cnt);
		int remainder = weight % p[i++].first;

		weight = remainder;
	}

	return maxValue;
}

int main() {
	int N, weight;
	cin >> N >> weight;

	pair<int, int> p[1000]; // first : 무게, second : 값어치

	for (int i = 0; i < N; ++i)
		cin >> p[i].first >> p[i].second;

	cout << UnboundedKnapspack(p, N, weight) << endl;
	return 0;
}
/*
unbounded knapspack 문제 정답


*/
