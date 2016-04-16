/*
정올 1060
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=340&sca=3020

최소비용신장트리 문제
채점 성공

너비우선탐색
그리디
프림 알고리즘

우선순위 큐 배열로 구현 해볼것
*/
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int MAX = 100;

typedef struct Graph {
	int dest, weight;
	Graph(int _dest, int _w) :dest(_dest), weight(_w) {}
	Graph() {}
};

int prim(vector<Graph>(&adj)[MAX], set<int> visited, int N) {
	// adj : 그래프 인접 리스트, visited : 사이클 체크용 visited 집합
	int sum = 0, key = 0, minWeight = MAX + 1;
	auto comp = [](const Graph& l, const Graph& r)-> bool {return l.weight > r.weight; }; // comparator 람다함수
	priority_queue < Graph, vector<Graph>, decltype(comp)> que(comp);	// 우선순위 큐

	while (!visited.empty()) {
		// 안전간선 (u,v) 찾기
		for (int i = 0; i < adj[key].size(); ++i) {
			Graph g = adj[key][i];
			if (visited.find(g.dest) != visited.end())
				que.push(g);
		}

		// STL priority queue의 특성상 iterator 사용이 불가능함에 따라 
		// 추가한 코드 - visited 된 간선 제거
		while (visited.find(que.top().dest) == visited.end())
			que.pop();

		sum += que.top().weight;
		int next = que.top().dest;
		visited.erase(next);
		que.pop();
		key = next;

	}

	return sum;
}

int main() {
	int N, w;
	vector<Graph> adj[MAX];
	set<int> vertex;

	cin >> N;

	for (int strt = 0; strt < N; ++strt)
		for (int dest = 0; dest < N; ++dest) {
			cin >> w;
			if (w != 0 && strt != dest)
				adj[strt].push_back(Graph(dest, w));
		}

	for (int v = 1; v < N; ++v)
		vertex.insert(v);

	cout << prim(adj, vertex, N) << endl;

	return 0;
}

/*
테스트 케이스

5
0 5 10 8 7
5 0 5 3 6
10 5 0 1 3
8 3 1 0 1
7 6 3 1 0
답 : 10

9
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
답: 37
*/