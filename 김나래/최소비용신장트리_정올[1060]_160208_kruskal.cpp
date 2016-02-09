/*
정올 1060
http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=340&sca=3020

최소비용신장트리 문제
채점 성공

그리디
서로소 집합 자료구조(disjoint set)
를 이용한 크루스칼 알고리즘
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
}G;

int findSet(vector<set<int>> disjointSet, int x) {
	for (int i = 0; i < disjointSet.size(); ++i)
		if (disjointSet[i].find(x) != disjointSet[i].end())
			return i;
	return -1;
}

int kruskal(vector<G>& edges, int N) {
	vector<set<int>> disjointSet;		// 서로소 집합
	//set<G> A;
	int sum = 0;

	// make-set(x) :  x를 유일한 원소로 가지는 집합 생성
	for (int v = 0; v < N; ++v) {
		set<int> tmp;
		tmp.insert(v);
		disjointSet.push_back(tmp);
	}

	for (int e = 0; e < edges.size(); ++e) {
		int su, sv;
		// find-set 연산
		if ((su = findSet(disjointSet, edges[e].u)) !=
			(sv = findSet(disjointSet, edges[e].v))) {
			sum += edges[e].w;
			// A.insert(edges[e]); 안전 간선 집합을 구하고 싶을 때 
			// union 연산
			disjointSet[su].insert(disjointSet[sv].begin()
				, disjointSet[sv].end());
			// union 한 다른 집합 지우기
			disjointSet.erase(disjointSet.begin() + sv);	
		}

		if (disjointSet.size() == 1) break;
	}

	return sum;
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