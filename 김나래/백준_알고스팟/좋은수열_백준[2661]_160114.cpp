/*
���� ���� / ����

https://www.acmicpc.net/problem/2661

ä�� ����
���� �켱 Ž�� (��� Ǯ��)
�� Ʈ��ŷ
-> ���̿켱Ž�� �Ϲ� ���� ���� Ǯ�� �ʿ�.
==> �Լ� ȣ���� ���� �ص� �ð��ʰ��� ���� �� �� ����.
*/
#include <iostream>
#include <string>

using namespace std;

string search(int N, string pre) {
	string res;
	if (pre.length() == N) return pre;

	for (int i = 0; i < 3; ++i) {
		bool isGood = true;
		if (i + 1 != (pre.back() - '0')) {
			string tmp = pre + to_string(i + 1);
			int len = tmp.length();
			for (int i = 1; i < len / 2; ++i) {
				if (tmp.substr(len - 2 * i - 2, i + 1).compare(
					tmp.substr(len - i - 1, i + 1)) == 0) {
					isGood = false;
				}
			}

			if (isGood) {
				if ((res = search(N, tmp)) != "")
					return res;
			}
		}
	}
	return "";
}

int main() {
	int N;

	cin >> N;

	cout << search(N, "1") << endl;
	return 0;
}