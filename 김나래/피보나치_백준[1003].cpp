#include <stdio.h>
#include <vector>

using namespace std;


int fiboTailRec(int n, int before, int next) {
	if (n == 0) 
		return before;
	else 
		return fiboTailRec(n - 1, next, before + next);
}

int fibonacci(int n, int init0, int init1) {
	return fiboTailRec(n, init0, init1);
}

int main() {
	int T;
	vector<pair<int,int>> res;
	int N, cnt0,cnt1;

	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		scanf("%d", &N);
		
		res.push_back(pair<int, int>(fibonacci(N, 1, 0)
					, fibonacci(N, 0, 1)));
	}

	for (int i = 0; i < res.size(); ++i) {
		printf("%d %d\n", res[i].first, res[i].second);
	}

	return 0;
}