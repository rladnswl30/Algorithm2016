#include <iostream>
#include <math.h>
#include <climits>

using namespace std;

inline void swap(int &i, int &j) {
	int t = i;
	i = j;
	j = t;
}

// N! 만큼의 그래프 이동 경로 경우수 만큼 모든 경우수를
// 고려해서 가장 최소의 길이를 찾는 알고리즘 
void perm(pair<int, double>(&adj)[12][12], int(&nums)[12], const int &N, int i, double &min, int(&res)[12]) {
	double sum = 0;
	if (i == N - 1) {
		int pos = 0;
		for (int n = 0; n < N; ++n) {
			sum += adj[pos][nums[n] + 1].second;
			pos = adj[pos][nums[n] + 1].first;
		}
		sum += adj[pos][N + 1].second; // 마지막 구하기
		if (sum < min) {
			copy(nums, nums + N, res);
			min = sum;
		}
	}

	for (int j = i; j < N; j++) {
		swap(nums[i], nums[j]);				  // swap
		perm(adj, nums, N, i + 1, min, res);   // recursive
		swap(nums[i], nums[j]);				  // swap it back
	}
}

int main() {
	double v[12][2], min = DBL_MAX;
	int N, t[12], res[12];
	pair<int, double> adj[12][12];

	cin >> N;

	v[0][0] = 0; v[0][1] = 0;
	for (int i = 1; i <= N; ++i) {
		cin >> v[i][0] >> v[i][1];
		t[i - 1] = i - 1;
	}
	v[N + 1][0] = 10; v[N + 1][1] = 10;

	for (int i = 0; i < N + 1; ++i) {
		for (int j = 0; j <= N + 1; ++j) {
			if (i == j || j == 0) continue;
			if (i == 0 && j == N + 1) continue;
			double weight = sqrt(pow(v[i][0] - v[j][0], 2.0)
				+ pow(v[i][1] - v[j][1], 2.0));
			adj[i][j] = make_pair(j, weight);
		}
	}

	perm(adj, t, N, 0, min, res);

	cout << "(0,0) -> ";
	for (int i = 0; i < N; ++i)
		cout << "(" << v[res[i] + 1][0] << "," << v[res[i] + 1][1] << ") -> ";
	cout << "(10,10)" << endl;

	return 0;
}