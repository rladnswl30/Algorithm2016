#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
	int N;
	string road[10];
	int D[10][10];		// 최소값을 받을 테이블 기록
	queue<int> que;

	cin >> N;

	// cin 사용 후 getline 을 이용해 string 입력시 개행 처리
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// road 에 진흙탕의 오염도를 입력 받기
	for (int i = 0; i < N; ++i) {
		getline(cin, road[i]);
		for (int j = 0; j < N; ++j) {
			road[i][j] -= '0';
			D[i][j] = 0xfffffff;		// 최대값 세팅
		}
	}

	// 너비우선 탐색 + 동적 프로그래밍으로 속도 개선
	// 너비우선탐색으로 갱신된 지점부터 다시 탐색
	que.push((N - 1)*N);
	D[N - 1][0] = 0;
	while (!que.empty()) {
		int i = que.front() / N;
		int j = que.front() % N;
		que.pop();

		if (D[i][j] >= 100) D[i][j] = 100;
		// 상
		if (i - 1 >= 0 && D[i - 1][j] > road[i - 1][j] + D[i][j]) {
			D[i - 1][j] = road[i - 1][j] + D[i][j];
			que.push((i - 1)*N + j);
		}
		// 우
		if (j + 1 < N && D[i][j + 1] > road[i][j + 1] + D[i][j]) {
			D[i][j + 1] = road[i][j + 1] + D[i][j];
			que.push(i*N + j + 1);
		}
		// 하
		if (i + 1 < N && D[i + 1][j] > road[i + 1][j] + D[i][j]) {
			D[i + 1][j] = road[i + 1][j] + D[i][j];
			que.push((i + 1)*N + j);
		}
		// 좌
		if (j - 1 >= 0 && D[i][j - 1] > road[i][j - 1] + D[i][j]) {
			D[i][j - 1] = road[i][j - 1] + D[i][j];
			que.push(i*N + j - 1);
		}
	}

	cout << D[0][N - 1] << endl;

	return 0;
}