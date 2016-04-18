#include <iostream>
#include <string>

using namespace std;

int N;
unsigned int Min;
int visited[10][10];
string map[10];

// O(4^n) 시간 복잡도의 깊이우선 탐색 알고리즘
void explore(int pos, int acc) {
	int x = pos % N; // 맵상에서의 x
	int y = pos / N; // 맵상에서의 y

	visited[y][x] = 1;

	if (acc + map[y][x] >= 100) {
		visited[y][x] = 0;
		return;
	}

	// 골인 지점인지 확인후 가장 최소값을 저장한다.
	if (pos == N - 1) {
		Min = Min > acc + map[y][x] ? acc + map[y][x] : Min;
		visited[y][x] = 0;
		return;
	}

	// 상하좌우를 탐색하며 경로를 찾는다. 
	// 상
	if (y != 0 && !visited[y - 1][x])
		explore(pos - N, acc + map[y][x]);

	// 좌
	if (x != 0 && !visited[y][x - 1])
		explore(pos - 1, acc + map[y][x]);

	// 하
	if (y != N - 1 && !visited[y + 1][x])
		explore(pos + N, acc + map[y][x]);

	// 우
	if (x != N - 1 && !visited[y][x + 1])
		explore(pos + 1, acc + map[y][x]);

	visited[y][x] = 0;
}

int main() {
	cin >> N;

	Min = 0x1000000;

	// cin 사용 후 getline 을 이용해 string 입력시 개행 처리
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// map 에 진흙탕의 오염도를 입력 받기
	for (int i = 0; i< N; ++i) {
		cin >> map[i];
		for (int j = 0; j< N; ++j) {
			map[i][j] -= '0';
			visited[i][j] = 0;
		}
	}

	// visited 테이블을 이용한 깊이우선 탐색 수행
	explore(N*(N - 1), 0);

	if (Min == 0x1000000) cout << "100" << endl;
	else cout << Min << endl;

	return 0;
}