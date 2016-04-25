#include <iostream>
#include <sstream>
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
	vector<string> para; // ´Ü¶ô
	vector<D> d;

	while (1) {
		string str;
		getline(cin, str);
		if (str == "") break;
		para.push_back(str);
	}

	for (int i = 0; i < para.size(); ++i) {

		string idx;
		int first = true;

		transform(para[i].begin(), para[i].end(), para[i].begin(), tolower);
		stringstream stream(para[i]);
		string token;

		while (stream >> token) {
			string key;
			int s = 0, e = token.size() - 1;

			while (!(token[s] >= 'a' && token[s] <= 'z')) { s++; }
			key += token[s];
			while (!(token[e] >= 'a' && token[e] <= 'z')) { e--; }
			key += token[e];

			int i;
			for (i = 0; i < d.size(); ++i) {
				if (d[i].str == key) {
					d[i].cnt++;
					break;
				}
			}
			if (i == d.size())
				d.push_back(D(key, 1));
		}
	}

	for (int i = 0; i < d.size(); ++i)
		cout << d[i].str << " , " << d[i].cnt << endl;

	return 0;
}