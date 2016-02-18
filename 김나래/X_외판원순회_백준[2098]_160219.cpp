/*
외판원 순회
https://www.acmicpc.net/problem/2098

구현중

푸는방법
1. dfs	(완전탐색)
2. 동적 프로그래밍
3. branch and bound (근사 알고리즘)
4. 최소신장트리 이용(삼각부등식 성립시만 유효, 근사 알고리즘)

테스트 케이스
4
0 10 15 20
5  0  9 10
6 13  0 12
8  8  9  0
답 : 35

0 2 9 0
1 0 6 4
0 7 0 8
6 3 0 0
답 : 
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = 1000001;


void subset(vector<set<int>> &A,int n) {
	for (int i = 0; i < (1 << (n)); i++) 
		for (int j = 0; j < n; j++)
			if (i & (1 << j))
				A[i].insert(j);
}

int DP_tsp(int (&adj)[16][16], int N) {
	int dp[16][32678];
	fill(&dp[0][0], &dp[0][0] + sizeof(dp), 0);

	vector<set<int>> A;
	set<int>::iterator it;
	subset(A, N);

	for (int i = 0; i < N; ++i)
		dp[i][0] = adj[i][0];

	for (int i = 0; i < N - 2; ++i) {
		for (int a = 0; A[a].size() == i + 1; ++a) {
			for (it = A[a].begin(); it != A[a].end(); ++it) {
				int j = *it;
				if (j != a)
					if ((adj[i][j] != INF) && (dp[j][0] != INF))
						if (dp[i][a] > adj[i][j] + dp[j][0])
							dp[i][a] = adj[i][j] + dp[j][0];
					else
						dp[i][a] = INF;
			}
		}
	}

	return 0; // 맨마지막꺼 리턴
}

int main() {
	int adj[16][16], N, input;

	cin >> N;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			cin >> input;
			adj[i][j] = input == 0? INF : input;
		}
	
	cout << DP_tsp(adj, N) << endl;

	return 0;
}




// TODO
int DFS_tsp(int(&adj)[16][16], int N);
int BnB_tsp(int(&adj)[16][16], int N);
int Approx_MST_tsp(int(&adj)[16][16], int N);

/*
문제풀이 참고 사이트
http://hochulshin.com/travelling-salesman-problem/

Pseudo code

int W[][] //그래프의 간선 길이 
int D[][] //n, V-{v1} 

tsp(n){ //n: 정점의 수
	for(int i = 2; i<= n-2; i++){
		D[i][0] = W[i][1] //D[vi][0]를 W[i][1]로 초기화
	}
	for(int k = 1; k<= n-2; k++)
		for k개의 정점을 포함한 V-{v1}의 모든 subset에 대해
			for A에 속하지 않고 v1이 아닌 vi에 대해
				D[i][A] = min(W[i][j] + D[vj]][A-{vj}])
	D[1][V-{v1}] = min(W[1][j] + D[vj][A - {v1}])
	return D[1][v-{v1}]
}

void subset(vector<list<int>> &A, int n) {
	int vertex[16];
	for (int i = 1; i < n; ++i)
		vertex[i] = i;

	for (int i = 0; i < n; ++i)
		aux(vertex, n, i, 0, A[i]);
}

void aux(int arr[],int size, int left, int index, list<int> &powerSet) {
	if (left == 0) return; 

	for (int i = index; i<size; i++) {
		powerSet.push_back(arr[i]);
		aux(arr, size, left - 1, i + 1, powerSet);
		powerSet.pop_back();
	}
}

참고 
비트 연산으로 부분집합 구하기
http://dumpsys.blogspot.kr/2015/03/algorithm-binary-counting-power-set.html
http://graphics.stanford.edu/~seander/bithacks.html#NextBitPermutation
비트 permutation 

*/