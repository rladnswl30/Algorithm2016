#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

typedef struct Edge {
	int v;
	float w;
	Edge(int _v, float _w) :v(_v), w(_w) {}
	Edge() {}
	bool operator < (const Edge v1) const { return v1.w < w; }
}Edge;

int main() {
	Edge adj[100][12];
	float V[10][2];
	int N;
	
	cin >> N;
	for(int i=0; i< N; ++i)
		cin >> V[i][0] >> V[i][1];

	for(int i=0; i<N; ++i){
		for(int j=0; j< N; ++j){
			if(i == j) continue;
			if(i == 0 && j == N-1) continue;
			float weight = sqrt(pow(V[i][0]-V[j][0],2) + pow(V[i][1]-V[j][1],2);
			adj[i].push_back(Edge(j, weight));
		}
	}

	for(int i=0; i<N+2; ++i){
		cout << ans[i] << endl;
		if(i != N-1) cout << " -> ";
		else cout << endl;
	}

	return 0;
}
