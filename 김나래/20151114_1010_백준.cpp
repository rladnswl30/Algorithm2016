/*
* https://www.acmicpc.net/problem/1010
* 다리 놓기
*/

#include <stdio.h>


unsigned long long Combination(int n, int k) {
	unsigned long long a = 1, r = 1;
	int i, j=1, tt=0;

	for(i =n; i >n-k; --i){
		a *= i;
		r *= j;
		j++;
	}
	
	return a / r;
}

int main(){
	int C;
	int N[30] = {'\0'};
	int M[30] = {'\0'};
	int i,j,diff;
	int r;
	unsigned long long res = 0;
	scanf("%d",&C);

	for(i=0; i<C; ++i){
		scanf("%d %d",&N[i],&M[i]);
		fflush(stdin);
	}

	for(i =0; i< C; ++i){
		res = 0;
		if( M[i]-N[i] == 0)
			res = 1;
		else if (N[i] ==1)
			res = M[i];
		else{
			if(N[i] > M[i]-N[i])
				r = M[i]-N[i];
			else
				r = N[i];

			res=Combination(M[i],r);
		}

		printf("%llu\n",res);
	}

}