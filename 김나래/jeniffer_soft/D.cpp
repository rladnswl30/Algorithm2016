#include <iostream>

using namespace std;

int dfs(int (&road)[10][10],bool (&visited)[10][10],const int N,int i,int j){
	
	if(i == 0 && j == N-1) return min;

	int min = 101;
	int res[4];
	// Up
	if( i+1 < N && visited[i+1][j] == false )
		res[0] = dfs(road,visited,N,i+1,j));

	// right
	if( j+1 < N && visited[i][j+1] == false)
		res[1] = dfs(road,visited,N,i+1,j);

	// down
	if( i-1 >=0 && visited[i-1][j] == false)
		res[2] = dfs(road,visited,N,i+1,j);

	// left
	if( j-1 >=0 && visited[i][j-1] == false)
		res[3] = dfs(road,visited,N,i+1,j);

	for(int d=0; d< 4; ++d)
		if(res[d] < min) min = res[d];

	return min;
}

int main(){
	int N, road[10][10];
	bool visited[10][10];
	fill(visited, visited+sizeof(visited), false);

	cin >> N;
	for(int i=0; i< N;++i)
		for(int j=0; j< N; ++j)
			cin >> road[i][j];

	dfs(road,visited,N, N-1, 0);

	return 0;
}