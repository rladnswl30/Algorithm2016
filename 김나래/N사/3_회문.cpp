/*
N�� 3�� ����

ȸ�� (palindrome) ����
*/
#include <iostream>
#include <exception>
#include <string>

using namespace std;

int getInput()
{
	string line;
	int number = 0;
	getline(cin, line);
	try {
		number = stoi(line);
	}
	catch (exception& e) {
		number = -1;
	}
	return number;
}


int main(void)
{
	// ǥ�� �Է����κ��� �ڿ����� �о����
	int number = getInput();

	for (int i = 0; i < 3; ++i) {
		int tmp = number, rev = 0;
		while (tmp > 0) {
			rev += (tmp % 10);
			tmp /= 10;
			if (tmp > 0) rev *= 10;
		}

		int res = number + rev;
		int len = 0;
		tmp = res;
		while (tmp > 0) {
			++len;
			tmp /= 10;
		}

		bool palindrome = true;
		string cmp = to_string(res);
		for (int j = 0; j < len / 2; ++j) {
			if (cmp[j] != cmp[len - j - 1]) {
				palindrome = false;
			}
		}

		if (palindrome) {
			cout << res << endl;
			return 0;
		}

		number = res;
	}

	cout << -1 << endl;

	return 0;
}
