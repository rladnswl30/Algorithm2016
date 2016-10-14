/*
N �� 1�� ����
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
	// ǥ�� �Է����κ��� �ִ� 10���� �ڿ����� ���� ���·� �о����
	vector<int> numbers = getInput(10);

	// ������ ���� ������� numbers ���Ϳ� number ������ ����� �� ����
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