/*
2015.11.16 피보나치 
https://www.acmicpc.net/problem/1003
꼬리 재귀 
*/

#include <iostream>
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
	int T, N;
	vector<pair<int,int> > res;

	cin>>T;

	for (int i = 0; i < T; ++i) {
		cin>>N;
		res.push_back(pair<int, int>(fibonacci(N, 1, 0)
					, fibonacci(N, 0, 1)));
	}

	for (int i = 0; i < res.size(); ++i)
		cout<<res[i].first<<" "<<res[i].second<<endl;

	return 0;
}