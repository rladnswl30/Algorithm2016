/*
최소비용 구하기
다익스트라
백준
https://www.acmicpc.net/problem/1916

채점성공
*/

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <climits>

using namespace std;

long long INF = LLONG_MAX;

typedef struct Edge {
	int v;
	long long w;
	Edge(int _v, long long _w) :v(_v), w(_w) {}
	Edge() {}
	bool operator < (const Edge v1) const { return v1.w < w; }
}Edge;

long long Dijkstra(vector<Edge>(&adj)[1010], int start, int end, int N) {
	priority_queue<Edge>Q;
	long long d[1010];

	for (int i = 1; i < N + 1; ++i)
		d[i] = (i == start) ? 0 : INF;

	int next = start;
	do {
		for (int i = 0; i < adj[next].size(); ++i) {
			int v = adj[next][i].v;
			if (d[v] > d[next] + adj[next][i].w) {
				d[v] = d[next] + adj[next][i].w;
				Q.push(adj[next][i]);
			}
		}

		if (Q.empty()) break;

		next = Q.top().v;

		Q.pop();
	} while (1);

	return d[end];
}

int main() {
	int n, m, start, end;
	long long weight;
	vector<Edge> adj[1010];

	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		cin >> start >> end >> weight;

		adj[start].push_back(Edge(end, weight));
	}

	cin >> start >> end;

	cout << Dijkstra(adj, start, end, n) << endl;

	return 0;
}

/*
테스트 케이스

5 9
1 2 2
1 3 3
1 4 1
1 4 10
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5
답: 4

5 12
1 2 10
1 4 5
2 4 2
2 3 1
3 5 4
4 2 3
4 5 2
4 3 9
5 1 7
5 1 9
5 3 6
5 3 9
1 5
답 : 7
*/
