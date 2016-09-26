/*
합친 LIS 
https://algospot.com/judge/problem/read/JLIS

채점 성공

동적 계획법
*/

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

// longest increasing subsequence
void LIS(set<int>& res, int* arr,int size) {
	set<int>::iterator it;

	for(int i=0; i< size; ++i){
		res.insert(arr[i]);
		it = upper_bound(res.begin(), res.end(), arr[i]);
		if(it != res.end())
			res.erase(it);
	}
}

int main() {

	int T,N,M;

	cin >> T;

	int* res= new int[T];
	for (int t = 0; t < T; ++t) {
		cin >> N >> M;
		int A[100], B[100];
		set<int> setA, setB;
		set<int>::iterator it;

		for (int n = 0; n < N; ++n)
			cin >> A[n];
		for(int m =0; m< M; ++m)
			cin >> B[m];
		
		LIS(setA,A,N);
		LIS(setB,B,M);

		setA.insert(setB.begin(), setB.end());
		res[t] = setA.size();
	}

	for(int i=0; i< T; ++i)
		cout << res[i]<<endl;

	return 0;
}
