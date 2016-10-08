#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct Alpha {
	char	c;			// ���ĺ� �빮��
	int		count;		// �ش� ���� �󵵼�
	// ������ �����ε� �Լ� sort �� count ������ ����
	bool operator < (const Alpha r) const { return count <r.count; }
}Alpha;

int main() {

	vector<Alpha> cnt(26);			// ���ĺ� ���� 26 ��ŭ ����
	string s;						// �Է¹��� ���ڿ�

	for (int i = 0; i < 26; ++i) {	// �ʱ�ȭ
		cnt[i].c = 'A' + i;			// �빮�� �ʱ�ȭ
		cnt[i].count = 0;			// �󵵼� �ʱ�ȭ
	}

	getline(cin, s);				// ���ڿ� �Է� �ޱ�

	for (int i = 0; i< s.size(); ++i)
		cnt[s[i] - 'A'].count++;	// �ε��� �󵵼� ����

	sort(cnt.begin(), cnt.end());	// ����

	int i = 0;
	while (cnt[i].count == 0) { ++i; }	// ���� �� ���� ���ĺ� ��ġ ã��

	for (int k = i; k< 26; ++k)
		for (int j = 0; j < cnt[k].count; ++j)
			cout << cnt[k].c;		// ���

	return 0;
}