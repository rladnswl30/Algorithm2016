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

typedef struct Graph {
	int u, v, w;
	Graph(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
	Graph() {}
};

int kruskal(vector<Graph>& arr, int N) {
	vector<set<int>> s;
	bool noIntersect = true;
	for (int i = 0; i < N*N; ++i) {
		int j, u = arr[i].u, v = arr[i].v;
		for (j = 0; j < s.size(); ++j) {
			if (s[j].find(u) != s[j].end()
				|| s[j].find(v) != s[j].end()) {
				s[j].insert(u);
				s[j].insert(v);
				noIntersect = false;
				break;
			}
		}
		// intersect가 없으면 new..
		if (noIntersect) {
			set<int> tmp;
			tmp.insert(u);
			tmp.insert(v);
			s.push_back(tmp);
		}



		union();
	}

}

int main() {
	int N, w;
	vector<Graph> lst;

	cin >> N;

	for (int u = 0; u < N; ++u)
		for (int v = 0; v < N; ++v)
			if (w != 0 && u != v)
				lst.push_back(Graph(u, v, w));

	sort(lst.begin(), lst.end(), [](const void* l, const void* r) {
		return static_cast<const Graph*>(l)->w >
			static_cast<const Graph*>(r)->w;
	});

	kruskal(lst, N);

	return 0;
}