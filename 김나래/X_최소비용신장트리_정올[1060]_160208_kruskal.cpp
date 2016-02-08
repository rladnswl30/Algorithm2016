/*
정올 1060
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=340&sca=3020

최소비용신장트리 문제
구현중

너비우선탐색
그리디
크루스칼 알고리즘
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAX = 100;

typedef struct G {
	int u, v, w;
	G(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
	G() {}
};

int kruskal(vector<G>& arr, int N) {
	vector<set<int>> s;
	bool noIntersect = true, first = true;
	int uni, sum = 0, i = 1;

	set<int> tmp;
	tmp.insert(arr[0].u);
	tmp.insert(arr[0].v);
	s.push_back(tmp);

	while (s[0].size() < N + 1) {
		int j, u = arr[i].u, v = arr[i].v;
		for (j = 0; j < s.size(); ++j) {
			if (s[j].find(u) != s[j].end()
				|| s[j].find(v) != s[j].end()) {
				s[j].insert(u);
				s[j].insert(v);
				noIntersect = false;
				if (first) { uni = j; first = false; }
				else if (uni != j) {
					s[uni].insert(s[j].begin(), s[j].end());
					s[j].clear();
				}
			}
		}
		// intersect가 없으면 new set 생성
		if (noIntersect) {
			set<int> tmp;
			tmp.insert(u);
			tmp.insert(v);
			s.push_back(tmp);
		}
		++i;
	}
	return 0;
}

int main() {
	int N, w;
	vector<G> lst;

	cin >> N;

	for (int u = 0; u < N; ++u)
		for (int v = 0; v < N; ++v) {
			cin >> w;
			if (w != 0 && u != v)
				lst.push_back(G(u, v, w));
		}

	sort(lst.begin(), lst.end(), [](const G& l, const G& r) {return l.w > r.w; });
	kruskal(lst, N);

	return 0;
}