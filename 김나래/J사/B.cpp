#include <iostream>
#include <string>

using namespace std;

int main() {

	int N, count = 0;
	string seat[1000];				// 최대 좌석수 1000개 만큼 할당
	cin >> N;

	// cin 사용 후 getline 을 이용해 string 입력시 개행 처리
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	for (int i = 0; i< N; ++i)
		getline(cin, seat[i]);// 좌석 입력 받기

							  // O(n^2) 복잡도의 영화관 자리 선택 알고리즘
	for (int i = 0; i< N; ++i)
		for (int j = 0; j< N; ++j)
			if (j + 1 < N && seat[i][j] == '.' && seat[i][j + 1] == '.')
				count++;

	cout << count << endl;
	return 0;
}