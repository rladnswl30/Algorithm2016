/*
정올
배낭 채우기
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=561&sca=30&sfl=wr_subject&stx=%EB%B0%B0%EB%82%AD&sop=and

동적 프로그래밍
0-1 knnapspack
*/
#include <iostream>

using namespace std;

// 하향식
int BotKnapspack0_1(pair<int, int>(&p)[1000], int N, int weight) {

}

// 상향식
int TopKnapspack0_1(pair<int, int>(&p)[1000], int N, int weight) {

}

int main() {
	int N, weight;
	cin >> N >> weight;

	pair<int, int> p[1000]; // first : 무게, second : 값어치

	for (int i = 0; i < N; ++i)
		cin >> p[i].first >> p[i].second;

	cout << BotKnapspack0_1(p, N, weight) << endl;
	return 0;
}

/*
테스트 케이스
4 14
2 40
5 110
10 200
3 50
답 : 300

4 16
2 40
5 30
10 50
5 10
답 : 90
*/