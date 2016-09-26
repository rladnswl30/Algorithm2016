/*

면접에 늦었다 백준
https://www.acmicpc.net/problem/5014

채점 성공

BFS 이용
*/

#include <iostream>
#include <queue>

using namespace std;

int main(){
	int f, s, g, u, d, count =0;
	bool visited[1000001];
	queue<int> que;

	fill(visited, visited+sizeof(visited), false);
	cin >> f >> s >> g >> u >> d;

	que.push(s);
	while(!que.empty()){
		int level = que.size();
		bool flag =false;
		for(int i=0; i< level; ++i){
			int item = que.front();
			que.pop();
			if(item == g){
				cout << count << endl;
				return 0;
			}

			if( item + u <= f && visited[item+u] == false ){
				que.push(item+u);
				visited[item+u] = true;
				flag = true;
			}

			if(item - d > 0 && visited[item-d] ==false ){
				que.push(item-d);
				visited[item-d] = true;
				flag = true;
			}
		}
		if(flag)
			count++;
	}

	cout << "use the stairs" << endl;

	return 0;
}