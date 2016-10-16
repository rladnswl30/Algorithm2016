/*
2번

시간 복잡도 O(N^2) ==> quicksort 이므로 amortized ?? 복잡도 NlogN 
공간복잡도 O(N)

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int solution(vector<int> &A) {
	// write your code in C++11 (g++ 4.8.2)
	vector<pair<int, int>> r;

	for (unsigned int i = 0; i < A.size(); ++i) {
		r.push_back(pair<int, int>(A[i], i));
	}

	sort(r.begin(), r.end());
	int min = INT_MAX;
	for (unsigned int i = 0; i < r.size() - 1; ++i) {

		int diff = abs(r[i + 1].first - r[i].first);
		if (diff < min) {
			min = diff;
		}
	}

	return min;
}

int main() {
	vector<int> A;
	int item;
	
	while(cin >> item){
		A.push_back(item);
	}
	
	int res = solution(A);
	cout << res << endl;

	return 0;
}
