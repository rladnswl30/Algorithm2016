/*
최소비용 구하기
다익스트라
백준
https://www.acmicpc.net/problem/1916


푸는 중


*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct Adj {
	int v, w; // v : vertex, w : weight
	Adj(int _v, int _w) :v(_v), w(_w) {}
	Adj() {}
};

int Dijkstra(vector<Adj>(&adj)[1001], int start, int end) {
	auto comp = [](const Adj& l, const Adj& r)-> bool {return l.w < r.w; };
	priority_queue<Adj, vector<Adj>, decltype(comp)>que(comp);

	Adj next(start, 0);
	do {
		for (int i = 0; i < adj[next.v].size(); ++i) {
			que.push(adj[next.v][i]);
		}

		next.v = que.top().v;
		next.w += que.top().w;

	} while (!que.empty());

	return next.w;
}

int main() {
	int n, m, start, end, weight; // n : 정점 수 , m : 간선 수
	vector<Adj> adj[1001];

	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		cin >> start >> end >> weight;
		adj[start].push_back(Adj(end, weight));
	}

	cin >> start >> end;

	cout << Dijkstra(adj, start, end) << endl;

	return 0;
}

/*
테스트 케이스

5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5

답:
4

*/
