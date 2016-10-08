#include <iostream>
#include <math.h>
#include <climits>

using namespace std;

// inline 바꾸기 함수
inline void swap(int &i, int &j) {
	int t = i;
	i = j;
	j = t;
}

// N! 의 시간복잡도로 그래프 이동 경로 경우수 만큼 
// 모든 경우수를 고려해 가장 최소의 길이를 찾는 알고리즘 
void perm(pair<int, double>(&adj)[12][12], int(&nums)[12], const int &N, int i, double &min, int(&res)[12]) {
	double sum = 0;
	if (i == N - 1) {	// 정점 순서가 모두 정해지면 간선 가중치를 더해 최소값 비교
		int pos = 0;
		for (int n = 0; n < N; ++n) {
			sum += adj[pos][nums[n] + 1].second; // 정점의 간선 가중치 더하기
			pos = adj[pos][nums[n] + 1].first;	 // 도착 정점 -> 다음 시작 정점으로 갱신
		}
		sum += adj[pos][N + 1].second;			// 최종 도착 지점까지의 가중치 합하기
		if (sum < min) {
			copy(nums, nums + N, res);			// 최소 정점인 경우 경로 복사
			min = sum;
		}
	}

	// 재귀 루틴
	for (int j = i; j < N; j++) {
		swap(nums[i], nums[j]);				  // nums[i], nums[j] 위치 바꾸기
		perm(adj, nums, N, i + 1, min, res);  // 경우수 바꾸기
		swap(nums[i], nums[j]);				  // nums[i], nums[j] 위치 복원
	}
}

int main() {
	double v[12][2];		// 시작, 끝지점과 중간 휴지의 좌표 정점 저장
	double  min = DBL_MAX;	// 최소 경로를 위한 변수 초기화 (무한대) 
	int N, t[12], res[12];	//
							// 도착 정점(first), 시작-도착 정점사이 거리(second) 를 나타내는 인접리스트
	pair<int, double> adj[12][12];

	cin >> N;

	v[0][0] = 0; v[0][1] = 0;
	for (int i = 1; i <= N; ++i) {
		cin >> v[i][0] >> v[i][1];
		t[i - 1] = i - 1;
	}
	v[N + 1][0] = 10; v[N + 1][1] = 10;

	// 정점 간 거리를 계산, N^2 시간 복잡도
	for (int i = 0; i < N + 1; ++i) {
		for (int j = 0; j <= N + 1; ++j) {
			if (i == j || j == 0) continue;
			if (i == 0 && j == N + 1) continue;
			double weight = sqrt(pow(v[i][0] - v[j][0], 2.0)
				+ pow(v[i][1] - v[j][1], 2.0));
			adj[i][j] = make_pair(j, weight);
		}
	}

	// 모든 경로의 경우수를 고려한 permutaion 연산함수 호출
	perm(adj, t, N, 0, min, res);

	// 출력
	cout << "(0,0) -> ";
	for (int i = 0; i < N; ++i)
		cout << "(" << v[res[i] + 1][0] << "," << v[res[i] + 1][1] << ") -> ";
	cout << "(10,10)" << endl;

	return 0;
}