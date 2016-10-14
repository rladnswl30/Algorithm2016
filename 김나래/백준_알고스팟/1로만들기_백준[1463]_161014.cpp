/*
1로 만들기
백준

https://www.acmicpc.net/problem/1463

동적 프로그래밍
- top down 방법 

점화식 : D[n] = min{ D[n/2] | D[n/3],  D[n-1] }

채점 성공
*/
#include <iostream>
#include <limits>
#include <queue>

using namespace std;

const int max_int = numeric_limits<int>::max();

// 재귀 이용 topdown방법 : 시간 초과
void TopDown(int *D, int N, int res){

	if(N == 1){
		D[N] = res;
		return;	
	} 
	
	int min = max_int;
	if(N % 2 == 0) {
		TopDown(D, N/2, res+1);
		if(min > D[N/2]) min = D[N/2]; 
	}

	if(N % 3 == 0){
		TopDown(D, N/3, res+1);
		if(min > D[N/3]) min = D[N/3];
	}

	if(N - 1 > 0 ){
		TopDown(D, N-1, res+1);
		if(min > D[N-1]) min = D[N-1];
	}

	D[N] = min;
} 

// queue + DP 채점 성공
void BottomUp(int *D, int N){
	D[N] = 0;
	queue<int> que;
	que.push(N);

	while(!que.empty()){
		int size = que.size();
		for(int i=0; i< size; ++i){
			int n = que.front();
			que.pop();
			if(n == 1) return;

			if( n % 2 == 0 && D[n/2] > D[n]+1){
				D[n/2] = D[n]+1;
				que.push(n/2);
			}

			if( n % 3 == 0 && D[n/3] > D[n]+1){
				D[n/3] = D[n]+1;
				que.push(n/3);
			}

			if( n-1 > 0 && D[n-1] > D[n]+1){
				D[n-1] = D[n]+1;
				que.push(n-1);
			}
		
		}
		
	}
}

int main(){
	int N;
	cin >> N;

	int *D = new int[N+1]; // 동적 할당하면 std::fill 함수를 사용할 수 없다.

	for(int i=0; i< N+1; ++i)
		D[i] = max_int;

	BottomUp(D, N);
	cout << D[1] << endl;
	
	/* topdown일 경우 주석 해제
	TopDown(D, N, 0);
	cout << D[N] << endl;
	*/

	return 0;
}