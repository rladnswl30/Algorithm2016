#include <iostream>
#include <string>

using namespace std;

int N;
unsigned int Min;
int visited[10][10];
string map[10];

// O(4^n) �ð� ���⵵�� ���̿켱 Ž�� �˰���
void explore(int pos, int acc) {
	int x = pos % N; // �ʻ󿡼��� x
	int y = pos / N; // �ʻ󿡼��� y

	visited[y][x] = 1;

	if (acc + map[y][x] >= 100) {
		visited[y][x] = 0;
		return;
	}

	// ���� �������� Ȯ���� ���� �ּҰ��� �����Ѵ�.
	if (pos == N - 1) {
		Min = Min > acc + map[y][x] ? acc + map[y][x] : Min;
		visited[y][x] = 0;
		return;
	}

	// �����¿츦 Ž���ϸ� ��θ� ã�´�. 
	// ��
	if (y != 0 && !visited[y - 1][x])
		explore(pos - N, acc + map[y][x]);

	// ��
	if (x != 0 && !visited[y][x - 1])
		explore(pos - 1, acc + map[y][x]);

	// ��
	if (y != N - 1 && !visited[y + 1][x])
		explore(pos + N, acc + map[y][x]);

	// ��
	if (x != N - 1 && !visited[y][x + 1])
		explore(pos + 1, acc + map[y][x]);

	visited[y][x] = 0;
}

int main() {
	cin >> N;

	Min = 0x1000000;

	// cin ��� �� getline �� �̿��� string �Է½� ���� ó��
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// map �� �������� �������� �Է� �ޱ�
	for (int i = 0; i< N; ++i) {
		cin >> map[i];
		for (int j = 0; j< N; ++j) {
			map[i][j] -= '0';
			visited[i][j] = 0;
		}
	}

	// visited ���̺��� �̿��� ���̿켱 Ž�� ����
	explore(N*(N - 1), 0);

	if (Min == 0x1000000) cout << "100" << endl;
	else cout << Min << endl;

	return 0;
}