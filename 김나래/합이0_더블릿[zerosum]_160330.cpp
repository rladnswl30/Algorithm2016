/*
zerosum
더블릿

http://59.23.113.171/30stair/zerosum/zerosum.php?pname=zerosum

완전탐색
백 트래킹 + dfs
재귀 트리 말고 스택 이용한 dfs 풀이 공부

틀린답으로 나오지만 순서만 바뀌었을 뿐 맞았음

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

		stack[idx] = sign[s]; // 현재

		// 이 함수 호출 부분을 if 문과함께
		// num, sum 등의 메모리를 변경하면
		// 재귀 호출 하지 않고 구현 가능해 보임
		if (zeroSum(stack, resN, sign, N, sum +
			(sign[s] != ' ' && stack[tmp] == '+' ? num :
				sign[s] != ' ' && stack[tmp] == '-' ? -num :
				0)
			, num
			, idx + 1)) {
			memcpy(res[resN], stack, strlen(stack) + 1);
			resN++;
		}

		// 복원
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
테스트 케이스
입력: 7
답 : 
1+2-3+4-5-6+7
1+2-3-4+5+6-7
1-2+3+4-5+6-7
1-2-3-4-5+6+7
1-2 3+4+5+6+7
1-2 3-4 5+6 7

*/