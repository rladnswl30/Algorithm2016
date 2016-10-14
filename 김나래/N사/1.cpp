/*
N 사 1번 문제
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<int> getInput(ssize_t sizeLimit)
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

	// 다음과 같은 방식으로 numbers 벡터와 number 변수를 사용할 수 있음
	/*
	for_each(numbers.begin(), numbers.end(), [] (int number) {
		cout << "number=" << number << endl;
	});
	cout << numbers[0] << endl;
	for (vector<int>::const_iterator iter = numbers.begin(); iter != numbers.end(); ++iter) {
		cout << "number=" << *iter << endl;
	}
	*/

	sort(numbers.begin(), numbers.begin() + numbers.size());
	int min = INT_MAX, minSum = INT_MAX, minIdx = 0;
	bool first = true;
	
	for (int i = 0; i < numbers.size() - 1; ++i) {
		if (numbers[i + 1] - numbers[i] <= min) {
			min = numbers[i + 1] - numbers[i];
			if (numbers[i + 1] + numbers[i] < minSum) {
				minSum = numbers[i + 1] + numbers[i];
				minIdx = i;
			}
		}
	}
	cout << numbers[minIdx] << " " << numbers[minIdx + 1] << endl;
	
	return 0;
}