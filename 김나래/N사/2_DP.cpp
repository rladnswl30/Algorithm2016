/*
N사 2번 문제

동적 프로그래밍

*/
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> getInput(ssize_t sizeLimit)
{
	vector<string> tokenVector;
	string line;
	getline(cin, line);
	istringstream iss(line);
	string token;
	while (getline(iss, token, ' ')) {
		tokenVector.push_back(token);
		if (tokenVector.size() >= sizeLimit) {
			break;
		}
	}
	return tokenVector;
}


int main(void)
{
	// 표준 입력으로부터 최대 10개의 문자열 토큰을 벡터 형태로 반환받음
	vector<string> words = getInput(10);


	int vowel = 0, alpha = 0;

	for (auto &word : words) {
		bool done[2] = { false,false };
		bool first[2] = { true,true };
		int d[20][2];
		for (int i = 0; i < 20; i++)
			for (int j = 0; j < 2; j++)
				d[i][j] = 0;

		for (int i = 0; i< word.size(); ++i) {
			char c = word[i];
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
				d[i][0] = 1;
				if (first[0])first[0] = false;
				else d[i][0] += d[i - 1][0];
				if (d[i][0] == 2 && !done[0]) {
					++vowel;
					done[0] = true;
				}
			}
			else {
				d[i][1] = 1;
				if (first[1]) first[1] = false;
				else d[i][1] += d[i - 1][1];
				if (d[i][1] == 3 && !done[1]) {
					++alpha;
					done[1] = true;
				}
			}
		}
	}

	cout << vowel << endl;
	cout << alpha << endl;

	return 0;
}