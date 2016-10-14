/*
컨닝 2 백준
https://www.acmicpc.net/problem/11014


최대 독립집합 문제
Maximum Independent Set Problem 

채점 성공

*/

#include <iostream>
#include <algorithm>

using namespace std;

// 완전 탐색 (백트래킹)
int completeSearch(char (&seats)[80][80], const int N, const int M, int res){

	//cout << "res!! "<< res << endl;
	int max = 0, result;
	bool flag =true;
	for(int n = N-1; n>=0; --n){
		for(int m=0; m < M; ++m){
			bool changed[4] = {false,false,false,false};
			if(seats[n][m] == '.'){
				// 마킹
				seats[n][m] = '*';

				// 오른쪽
				if( m+1 < M && seats[n][m+1] == '.'){
					seats[n][m+1] = '/';
					changed[0] = true;
				}
 
				// 왼쪽
				if( m-1 >=0 && seats[n][m-1] == '.'){
					seats[n][m-1] = '/';
					changed[1] = true;
				}

				// 오른쪽 위 
				if( n-1 >=0 && m+1 < M && seats[n-1][m+1] == '.' ){
					seats[n-1][m+1] = '/';
					changed[2] = true;
				} 

				// 왼쪽 위
				if( n-1 < N && m-1 < M && seats[n-1][m-1] == '.' ){
					seats[n-1][m-1] = '/';
					changed[3] = true;
				}

				/*for(int i=0; i< N; ++i){
					for(int j=0; j< M; ++j){
						cout << seats[i][j];	
					}
					cout <<endl;
				}
				cout << "="<<endl;*/

				result = maxSeatSearch(seats, N, M, res+1);

				if(result > max )
					max = result;

				// cout << "result : " << result << " max : " << max << endl; 

				seats[n][m] = '.';

				// 오른쪽
				if( changed[0]) 
					seats[n][m+1] = '.';
 
				// 왼쪽
				if( changed[1]) 
					seats[n][m-1] = '.';

				// 오른쪽 위 
				if( changed[2] ) 
					seats[n-1][m+1] = '.';

				// 왼쪽 위
				if( changed[3] )
					seats[n-1][m-1] = '.';

				flag= false;

			} else{
				result = res;
			}
		}
	}

	if(flag)
		return res;
	else 
		return max;

}

int main(){
	int C, N, M;
	char seats[80][80];

	fill(&seats[0][0], (&seats[0][0]) + sizeof(seats), -1);

	cin >> C;
	for(int c=0; c < C; ++c){
		cin >> N >> M;
		int size = N*M;

		for(int n=0; n < N; ++n){
			for(int m=0; m < M; ++m){
				cin >> seats[n][m];
				if(seats[n][m] == 'x')
					--size;
			}
		}

		int max = completeSearch(seats, N, M, 0);
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

