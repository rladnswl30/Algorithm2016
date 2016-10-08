#include <iostream>
#include <string>

using namespace std;

int makeJenniferSoft(string X, string Y) {
	// JENNIFERSOFT�� 12 ���ڿ� �Է� ���ڿ� �ִ� ������ 1000���� ���� �迭 �Ҵ�
	int L[1000][12];
	int res = 0, preX, preY;
	char lcs[1000];		 // ���ڿ� lcs�� �ϼ��� �ӽ� �迭 ����
	fill(lcs, lcs + sizeof(lcs), -1);

	// ���� ���� �κ� ���ڿ� ã�� ���� ���α׷��� �˰���
	for (int i = 0; i <= X.size(); i++) {
		for (int j = 0; j <= Y.size(); j++) {
			// �� ���ڿ��� �׳� ���ڿ� �񱳴� ����κ��� �׻� 0 �̹Ƿ� 0���� �ʱ�ȭ
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (X[i - 1] == Y[j - 1]) { // ����κ� �߽߰� ����κ� �󵵼� ����
				L[i][j] = L[i - 1][j - 1] + 1;
				preX = i - 1; preY = j - 1;
			}
			else // lcs(i-1������ X, j������ jennifer)�� lcs(i������ X, j-1������ jennifer)�� �ִ밪 ���ϱ� 
				L[i][j] = L[i - 1][j]< L[i][j - 1] ?
				L[i][j - 1] : L[i - 1][j];
		}
	}

	// 2. �������ϸ鼭 ����, ����, ���� Ƚ�� ã��
	// ����, ����, ����Ƚ���� �� ���ڿ� �� ���� ���� ������ ���̰� ū ���� 
	// Ƚ���� �ȴ�. aabccd �� fbsssd ���� ���� �κ� ���ڿ��� bd �̰� 
	// ù ���� ���� b�� ��Ÿ���� ���� 2�� aabccd ������ 2��,fbsssd ������ 1�� �ٸ� ���ڰ�
	// ��ϵȴ�. fbssd�� aabccd�� �Ǳ� ���ؼ��� f�ϳ��� a�� �����ϰ� a �� �ϳ� �߰��ؾ��ϰ�
	// fbsssd�� aabccd�� �Ǳ����� b�� d���̿��� 2���� ����� 1���� ������ �ʿ��ϴ�
	// �ݴ��� ��쵵 �� ���ڰ� ���̰� ����� �� ���� ���� ����Ƚ���� �ȴ�.
	int i = X.size(), j = Y.size();
	bool first = true;
	// ù��° ���� ���ڰ� ��Ÿ���� ���� �ִ� ���̸� ã�� ���ϱ�
	if (preX < X.size() - 1 || preY < Y.size() - 1)
		res += X.size() - 1 - preX < Y.size() - preY - 1 ?
		Y.size() - preY - 1 : X.size() - 1 - preX;
	// �Ϲ����� ������ �˰���
	while (i > 0 && j > 0)
	{
		if (X[i - 1] == Y[j - 1]) {
			lcs[i - 1] = X[i - 1];
			if (first) first = false;
			else
				res += (preX - i) < (preY - j) ? preY - j : preX - i;
			preX = i - 1; preY = j - 1;
			i--; j--;
		}
		else if (L[i - 1][j] > L[i][j - 1])
			i--;
		else
			j--;
	}
	// ������ ���� ���ڿ� ������ ������ ���� �� ū���� ��� ���ϱ�
	res += preX < preY ? preY : preX;
	// ��� ��ȯ
	return res;
}

int main() {
	string m, n = "JENNIFERSOFT";

	getline(cin, m);
	cout << makeJenniferSoft(m, n) << endl;

	return 0;
}