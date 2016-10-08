/*
N사 4번 시험문제

기수정렬 (radix sort) 변형 문제

*/
#include <iostream>
#include <sstream>
#include <numeric>
#include <queue>

using namespace std;

vector<int> getInput(size_t sizeLimit)
{
	vector<int> tokenVector;
	string line;
	getline(cin, line);
	istringstream iss(line);
	string token;
	while (getline(iss, token, ' ')) {
		try {
			tokenVector.push_back(stoi(token));
		}
		catch (exception& e) {
			continue;
		}
		if (tokenVector.size() >= sizeLimit) {
			break;
		}
	}
	return tokenVector;
}

int main(void)
{
	// 표준 입력으로부터 최대 10개의 자연수를 벡터 형태로 읽어들임
	vector<int> numbers = getInput(10);
	queue<int> radix[10];
	int maxDigit = 0;
	for (int i = 0; i < numbers.size(); ++i) {
		int digit = 0, num = numbers[i];
		while (num > 0) {
			num /= 10;
			++digit;
		}

		if (digit > maxDigit) maxDigit = digit;
	}

	string max = "", min = "";
	for (int j = 0; j < maxDigit; ++j) {
		int pre = 0;
		for (int i = 0; i < numbers.size(); ++i) {
			int n = numbers[i], digit = 0;
			while (n > 0) {
				n /= 10;
				++digit;
			}

			if (digit - j > 0) {
				pre = numbers[i] / (int)pow(10, j) % 10;
				radix[numbers[i] / (int)pow(10, j) % 10].push(numbers[i]);
			}
			else {
				// pre가 0 이면 radix sort 임
				radix[pre].push(numbers[i]);
			}
		}

		int r = 0;
		for (int k = 0; k < 10; ++k) {
			while (!radix[k].empty()) {
				numbers[r++] = radix[k].front();
				radix[k].pop();
			}
		}
	}

	cout << atoi(max.c_str()) + atoi(min.c_str()) << endl;

	return 0;
}