#include <iostream>
#include <string>

using namespace std;

int main() {

	int N, count = 0;
	string seat[1000];				// �ִ� �¼��� 1000�� ��ŭ �Ҵ�
	cin >> N;

	// cin ��� �� getline �� �̿��� string �Է½� ���� ó��
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	for (int i = 0; i< N; ++i)
		getline(cin, seat[i]);// �¼� �Է� �ޱ�

							  // O(n^2) ���⵵�� ��ȭ�� �ڸ� ���� �˰���
	for (int i = 0; i< N; ++i)
		for (int j = 0; j< N; ++j)
			if (j + 1 < N && seat[i][j] == '.' && seat[i][j + 1] == '.')
				count++;

	cout << count << endl;
	return 0;
}