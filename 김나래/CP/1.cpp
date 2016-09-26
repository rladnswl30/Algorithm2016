/*
입력:
Coupang is the fastest growing e-commerce company and continuing to gain growth momentum.
At the same time, Coupang is now conquering Korea.

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct D {
	string str;
	int cnt;
	D(string _str, int _cnt) : str(_str), cnt(_cnt) {}
	bool operator < (const D &rhs) const { return cnt > rhs.cnt; }
}Dic;

int main() {
	vector<D> d;
	vector<string> para; // 단락
	vector<D>::iterator it;

	while (1) {
		string str;
		getline(cin, str);
		if (str == "") break;
		para.push_back(str);
	}

	for (int i = 0; i < para.size(); ++i) {
		string s = para[i];	//문장
		string idx;
		int first = true;

		for (int j = 0; j < s.size(); j++) {
			if (s[j] == ' ') {
				if (j == 0) continue;

				if (s[j] >= 'A' && s[j] <= 'Z')
					s[j] += 32;

				int tmp = j;
				while (s[tmp - 1] == ',' || s[tmp - 1] == '.' ||
					s[tmp - 1] == '-') {
					--tmp;
				}
				idx += s[tmp - 1];

				int k = 0;
				for (k = 0; k < d.size(); ++k) {
					if (d[k].str[0] == idx[0] &&
						d[k].str[1] == idx[1]) break;
				}

				if (k != d.size()) ++d[k].cnt;
				else d.push_back(D(idx, 1));

				first = true;
				idx = "";
				continue;
			}
			if (first) {
				if (s[j] >= 'A' && s[j] <= 'Z')
					s[j] += 32;

				if (s[j] == ',' || s[j] == '.' || s[j] == '-')
					continue;

				idx += s[j];
				first = false;
			}
		}
	}

	sort(d.begin(), d.end());

	for (int i = 0; i < d.size(); ++i)
		cout << d[i].str << " , " << d[i].cnt << endl;

	return 0;
}