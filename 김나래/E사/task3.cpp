/*
3번

시간복잡도 O(N)
공간복잡도 O(N)

*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int solution(vector<int> &A) {
	// write your code in C++11 (g++ 4.8.2)
	vector<int> dp[2];

	for (unsigned int i = 0; i < A.size(); ++i) {
		dp[0].push_back(A[i]);
		dp[1].push_back(A[i]);
	}

	for (unsigned int i = 0; i < A.size() - 1; ++i) {
		if (dp[0][i] < A[i + 1]) {
			dp[0][i + 1] = A[i + 1];
		}
		else {
			dp[0][i + 1] = dp[0][i];
		}
	}

	for (unsigned int i = A.size() - 1; i > 0; --i) {
		if (dp[1][i] < A[i - 1]) {
			dp[1][i - 1] = A[i - 1];
		}
		else {
			dp[1][i - 1] = dp[1][i];
		}
	}

	int max = INT_MIN;
	for (unsigned int k = 0; k < A.size() - 1; ++k) {
		int diff = abs(dp[0][k] - dp[1][k + 1]);
		if (max < diff)
			max = diff;
	}

	return max;
}

int main() {
	vector<int> A;
	int item;

	while (cin >> item) {
		A.push_back(item);
	}

	int res = solution(A);
	cout << res << endl;

	return 0;
}