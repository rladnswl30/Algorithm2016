/*
개미
백준 [10158]
채점 성공

테스트 케이스
6 4
4 1
8
답 0 1

6 4
4 1
24
답 4 1

6 4
4 1
26
답 6 3

6 4
4 1
200000000
답 0 1
*/
#include <iostream>
#include <vector>

using namespace std;

enum direction{L, R, U, D};	// Left , Right, Up, Down
int w,h;

int nextDirect(int x, int& d ){
	switch(d){
	case L:
		if(x == 0){d = R; return w;}
		else return x;
	case R:
		if(x==w){d = L; return w;} 
		else return w-x;
	case U:
		if(x == h){d = D; return h;} 
		else return h-x;
	case D:
		if(x == 0){d = U; return h;} 
		else return x;
	}
	return 0;
}

int main(){

	int x, y, t;
	pair<int,int> pre, dir, next;

	cin >> w >> h;
	cin >> pre.first >> pre.second;
	cin >> t;

	dir.first = R;
	dir.second = U;
	while(t > 0){
		int x =nextDirect(pre.first,dir.first);
		int y =nextDirect(pre.second, dir.second);
		int diff = x < y ? x : y;

		if(t-diff < 0){
			next.first 	=  pre.first + (dir.first == L ? -t : +t );
			next.second =  pre.second + (dir.second == U? +t : -t );
			break;
		}

		next.first 	=  pre.first + (dir.first == L ? -diff : diff);
		next.second =  pre.second + (dir.second == U ? +diff : -diff); 
		
		pre.first 	= next.first;
		pre.second 	= next.second;
		
		t -=diff;
	}

	cout << next.first << " "<< next.second << endl;

	return 0;
}