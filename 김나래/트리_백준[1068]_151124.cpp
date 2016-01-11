/*
트리
https://www.acmicpc.net/problem/1068

채점 성공

테스트 케이스

=========
5
-1 0 0 1 1
2
답 : 2
=========
7
-1 0 0 1 -1 4 4
3
답 : 2
=========
5
-1 0 1 2 2
2
답 : 1
=========
5
2 4 4 2 -1
3
답 : 2
=========

*/
#include <iostream>  

using namespace std;

int countLeaf(int*& parent, bool*& visited, int node, int rmNode, int N) {
	int cnt = 0;
	bool leaf = true;

	if (node == rmNode)
		return 0;

	for (int i = 0; i < N; ++i) {
		if (!visited[i] && parent[i] == node) {
			visited[i] = true;
			leaf = false;
			cnt += countLeaf(parent, visited, i, rmNode, N);
		}
	}

	if (leaf || cnt == 0) return 1;
	else return cnt;
}


int main() {
	int N, rmNode, start, n = -1;
	bool first = true;
	cin >> N;

	int* tree = new int[N];
	bool* visited = new bool[N];
	for (int i = 0; i < N; ++i) {
		cin >> tree[i];
		visited[i] = false;
		if (tree[i] == -1) {
			if (first) {
				first = false;
				start = i;
			}
			else n = i;
		}
	}

	cin >> rmNode;

	cout << countLeaf(tree
		, visited
		, start
		, rmNode
		, n != -1 ? n : N) << endl;

	return 0;
}