/*
외판원 순회
https://www.acmicpc.net/problem/2098

채점 성공

푸는방법
1. dfs	(완전탐색)
2. 동적 프로그래밍
3. branch and bound (근사 알고리즘)

중 동적 프로그래밍 풀이
*/
#include <iostream>

using namespace std;

const int TOP = -1;
const int BOT = -5;

inline int min(int l, int r) { return (l == BOT || r == BOT) ? (l > r ? l : r) : (l < r ? l : r); }
inline int add(int l, int r) { return l == BOT || r == BOT ? BOT : l + r; }

int DP_BottomUp_TSP(int(&W)[16][16], int N) {

	int* D[16], vi, vj;
	const int ns = (1 << (N - 1)) - 1;	// 부분집합 개수

	for (int i = 0; i < N; ++i) {
		D[i] = new int[ns + 1];
		for (int j = 0; j < ns + 1; ++j)
			D[i][j] = TOP;
	}

	// v2->v1 , v3->v1 , ... vN ->v1 초기값 입력
	for (int i = 1; i < N; ++i)
		D[i][0] = W[i][0];

	// v2, v3, v4 ... vN -> ... -> v1 까지의 최소 값 구하기
	for (int S = 1; S < ns; ++S) {							// 부분집합 개수 : 비트연산을 통한 부분집합
		for (int i = 1; i < N; ++i) {						// 간선에서 출발 정점
			for (int j = 1; j < N; ++j) {					// 간선에서 도착 정점
				if ((vi = 1 << (i - 1)) & S) break;

				if (S & (vj = 1 << (j - 1))) {
					if (D[i][S] == TOP)
						D[i][S] = add(W[i][j], D[j][S - vj]);
					else
						D[i][S] = min(D[i][S], add(W[i][j], D[j][S - vj]));
				}
			}
		}
	}

	// v1 -> v1 까지의 경로 
	for (int j = 1; j < N; ++j) {
		vj = 1 << (j - 1);
		if (D[0][ns] == TOP) D[0][ns] = add(W[0][j], D[j][ns - vj]);
		else D[0][ns] = min(D[0][ns], add(W[0][j], D[j][ns - vj]));
	}

	return D[0][ns];
}


int main() {
	int W[16][16], N, input;

	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			cin >> input;
			W[i][j] = input == 0 ? BOT : input;
		}

	cout << DP_BottomUp_TSP(W, N) << endl;

	return 0;
}
/*
점화식
g(i,S) = min{Cij + g(j,S-{j}) }

테스트 케이스
4
0 10 15 20
5  0  9 10
6 13  0 12
8  8  9  0
답 : 35

4
0 2 9 0
1 0 6 4
0 7 0 8
6 3 0 0
답 : 21
*/