#include <iostream> 

using namespace std;

int recursive(int (&p)[10001],int n, int (&r)[1001]){
	int max =-1, res;
	if(n == 0 ) return 0;

	for(int i=1; i<= n; ++i){
		if(max < p[i]+ (res=recursive( p, n-i,r )))
			max = p[i]+res;
	}

	return max;
}

/*
top down과 bottom up 고민
*/

int TopDown(int (&p)[10001],int n, int (&r)[1001]){
	int max =-1, res;
	if(n ==0) return 0;

	for(int i=1; i< n; ++i){
		if(r[n-i] != -1) res = r[n-i];
		else TopDown(p, n-i, r);

		if(max < p[i]+ res))
			max = p[i]+res;
	}

	return max;
}

int BottomUp(int (&p)[10001], const int N){
	int r[1001];
	r[0] = 0;
	for(int j=1; j<= N; ++j ){
		int max  = -1;
		for( int i=1; i <= j; ++i){
			if( max < p[i]+ r[j-i] )
				max = p[i]+ r[j-i];
		}
		r[j] = max;
	}

	return r[N];
}

int main(){

	int p[10001];
	int N;

	cin >> N;
	for(int i=1; i<= N; ++i)
		cin >> p[i];

	int r[1001];
	fill(r, r+sizeof(r), -1);
	r[0] = 0;
	//cout << recursive(p, N, r) << endl;
	cout << TopDown(p, N) << endl;
	//cout << BottomUp(p, N) << endl;
	return 0;
}

