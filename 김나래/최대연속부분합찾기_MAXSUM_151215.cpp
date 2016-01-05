#include <iostream>

using namespace std;

int main(){
	int T, N;

	cin >> T;

	for(int t=0; t< T;++t){
		cin >> N;
		int* arr= new int[N];
		int max =0;
		for(int n=0; n < N;++n)
			cin >> arr[n];

		for(int i=0; i<N;++i)
			if (max < max+arr[i])
				max += arr[i];

		cout << max<< endl;
		delete [] arr;
	}

	return 0;
}