/*
zerosum
����

http://59.23.113.171/30stair/zerosum/zerosum.php?pname=zerosum

����Ž��
�� Ʈ��ŷ + dfs
��� Ʈ�� ���� ���� �̿��� dfs Ǯ�� ����

*/
#include <iostream>
#include <string>

using namespace std;

char res[729][9];

int zeroSum(char(&stack)[10], int& resN, const char(&sign)[3], const int N, int sum, int num, int idx) {
	int tmp = idx - 1;

	for (int s = 0; s < 3; ++s) {
		num = stack[idx - 1] == ' ' ? num * 10 + idx : idx;
		while (stack[tmp] == ' ') { tmp--; }

		if (idx == N) {
			if (sum + (stack[tmp] == '+' ? num : -num) == 0)
				return 1;
			else return 0;
		}

		stack[idx] = sign[s];		// ����

		if (zeroSum(stack, resN, sign, N, sum +
			(sign[s] != ' ' && stack[tmp] == '+' ? num :
				sign[s] != ' ' && stack[tmp] == '-' ? -num :
				0)
			, num
			, idx + 1)) {
			memcpy(res[resN], stack, strlen(stack) + 1);
			resN++;
		}

		// ����
		if (stack[idx - 1] == ' ') num = (num - idx) / 10;

	}

	return 0;
}

int main() {
	int N, resN = 0;
	char stack[10], sign[3] = { '+','-',' ' };

	stack[0] = '+';

	cin >> N;

	zeroSum(stack, resN, sign, N, 0, 1, 1);

	for (int i = 0; i < resN; ++i) {
		for (int j = 1; j < N + 1; ++j) {
			cout << j;
			if (j < N) cout << res[i][j];
		}
		cout << endl;
	}

	return 0;
}
/*
�׽�Ʈ ���̽�
�Է�: 7
�� : 
1+2-3+4-5-6+7
1+2-3-4+5+6-7
1-2+3+4-5+6-7
1-2-3-4-5+6+7
1-2 3+4+5+6+7
1-2 3-4 5+6 7

*/