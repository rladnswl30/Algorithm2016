/*
최대 독립 집합
https://www.acmicpc.net/problem/11014


백트래킹 
채점 성공

*/
#include <iostream>

using namespace std;

int bfs_dp(){
}


int main(){
	int C, N, M;
	char seat[80][80];
	//int adj[80];

	cin >> C;
	int *res = new int[C];

	for(int c=0; c<C; ++c){
		cin >> N >> M;
		fill(adj, adj+sizeof(adj), 0);

		for(int n=0; n<N; ++n){
			for(int m=0; m<M; ++m){
				cin >> seat[n][m];   
				//if(seat[n][m] == 'x')
				//	adj[m]++;
			}
		}
	}

	for(int c=0; c< C; ++c)
		cout << res[c] <<endl;

	return 0;
}
/*
테스트 케이스

4
2 3
...
...
2 3
x.x
xxx
2 3
x.x
x.x
10 10
....x.....
..........
..........
..x.......
..........
x...x.x...
.........x
...x......
........x.
.x...x....

*/