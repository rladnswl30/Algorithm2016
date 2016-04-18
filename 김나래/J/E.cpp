#include <iostream>
#include <string>

using namespace std;

int makeJenniferSoft(string X, string Y) {
	// JENNIFERSOFT의 12 문자와 입력 문자열 최대 길이인 1000으로 정적 배열 할당
	int L[1000][12];
	int res = 0, preX, preY;
	char lcs[1000];		 // 문자열 lcs에 완성할 임시 배열 저장
	fill(lcs, lcs + sizeof(lcs), -1);

	// 최장 공통 부분 문자열 찾기 동적 프로그래밍 알고리즘
	for (int i = 0; i <= X.size(); i++) {
		for (int j = 0; j <= Y.size(); j++) {
			// 빈 문자열과 그냥 문자열 비교는 공통부분이 항상 0 이므로 0으로 초기화
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (X[i - 1] == Y[j - 1]) { // 공통부분 발견시 공통부분 빈도수 증가
				L[i][j] = L[i - 1][j - 1] + 1;
				preX = i - 1; preY = j - 1;
			}
			else // lcs(i-1길이의 X, j길이의 jennifer)과 lcs(i길이의 X, j-1길이의 jennifer)의 최대값 구하기 
				L[i][j] = L[i - 1][j]< L[i][j - 1] ?
				L[i][j - 1] : L[i - 1][j];
		}
	}

	// 2. 역추적하면서 삽입, 삭제, 변경 횟수 찾기
	// 삽입, 삭제, 변경횟수는 두 문자열 중 공통 문자 사이의 길이가 큰 것이 
	// 횟수가 된다. aabccd 와 fbsssd 에서 공통 부분 문자열은 bd 이고 
	// 첫 공통 문자 b가 나타나기 까지 2번 aabccd 에서는 2번,fbsssd 까지는 1번 다른 문자가
	// 기록된다. fbssd가 aabccd가 되기 위해서는 f하나를 a로 변경하고 a 를 하나 추가해야하고
	// fbsssd가 aabccd가 되기위해 b와 d사이에는 2번의 변경과 1번의 삭제가 필요하다
	// 반대의 경우도 두 문자간 길이가 긴것이 총 삽입 삭제 변경횟수가 된다.
	int i = X.size(), j = Y.size();
	bool first = true;
	// 첫번째 공통 문자가 나타나기 까지 최대 길이를 찾아 더하기
	if (preX < X.size() - 1 || preY < Y.size() - 1)
		res += X.size() - 1 - preX < Y.size() - preY - 1 ?
		Y.size() - preY - 1 : X.size() - 1 - preX;
	// 일반적인 역추적 알고리즘
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
	// 마지막 공통 문자와 각문자 마지막 길이 중 큰것을 골라 더하기
	res += preX < preY ? preY : preX;
	// 결과 반환
	return res;
}

int main() {
	string m, n = "JENNIFERSOFT";

	getline(cin, m);
	cout << makeJenniferSoft(m, n) << endl;

	return 0;
}