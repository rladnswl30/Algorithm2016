/*
컨닝 2 백준
https://www.acmicpc.net/problem/11014


최대 독립집합 문제
Maximum Independent Set Problem 

푸는 중

*/

#include <iostream>
#include <algorithm>

using namespace std;

// 최대 독립집합 문제
// MIS : Maximal Independent Set 알고리즘
int MIS(char (&seats)[80][80], const int N, const int M, int res){

	set<pair<int,int>> s;
	for(int n = N-1; n >=0; ++n){
		for(int m = 0;  m < M; ++m){

			while(s.empty){

			}
			seats[n][m]
		}
	}
}

int main(){
	int C, N, M;
	int seats[80][80];

	cin >> C;
	for(int c=0; c < C; ++c){
		cin >> N >> M;
		int size = N*M;

		for(int n=0; n < N; ++n){
			for(int m=0; m < M; ++m){
				cin >> seats[n][m];
			}
		}

		int max = MIS(seats, N, M, 0);
		cout << max << endl;	
	}


}

/*

예제 :
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

답 : 
4
1
2
46


*/

