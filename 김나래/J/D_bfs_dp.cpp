#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
	int N;
	string road[10];
	int D[10][10];		// �ּҰ��� ���� ���̺� ���
	queue<int> que;

	cin >> N;

	// cin ��� �� getline �� �̿��� string �Է½� ���� ó��
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// road �� �������� �������� �Է� �ޱ�
	for (int i = 0; i < N; ++i) {
		getline(cin, road[i]);
		for (int j = 0; j < N; ++j) {
			road[i][j] -= '0';
			D[i][j] = 0xfffffff;		// �ִ밪 ����
		}
	}

	// �ʺ�켱 Ž�� + ���� ���α׷������� �ӵ� ����
	// �ʺ�켱Ž������ ���ŵ� �������� �ٽ� Ž��
	que.push((N - 1)*N);
	D[N - 1][0] = 0;
	while (!que.empty()) {
		int i = que.front() / N;
		int j = que.front() % N;
		que.pop();

		if (D[i][j] >= 100) D[i][j] = 100;
		// ��
		if (i - 1 >= 0 && D[i - 1][j] > road[i - 1][j] + D[i][j]) {
			D[i - 1][j] = road[i - 1][j] + D[i][j];
			que.push((i - 1)*N + j);
		}
		// ��
		if (j + 1 < N && D[i][j + 1] > road[i][j + 1] + D[i][j]) {
			D[i][j + 1] = road[i][j + 1] + D[i][j];
			que.push(i*N + j + 1);
		}
		// ��
		if (i + 1 < N && D[i + 1][j] > road[i + 1][j] + D[i][j]) {
			D[i + 1][j] = road[i + 1][j] + D[i][j];
			que.push((i + 1)*N + j);
		}
		// ��
		if (j - 1 >= 0 && D[i][j - 1] > road[i][j - 1] + D[i][j]) {
			D[i][j - 1] = road[i][j - 1] + D[i][j];
			que.push(i*N + j - 1);
		}
	}

	cout << D[0][N - 1] << endl;

	return 0;
}