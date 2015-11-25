/* 2015.11.14
*  algospot 타일링 문제
* https://algospot.com/judge/problem/read/TILING2
* nrkim
* 에러는 안나는데 답이 안나옴 100의 경우
*/

#include <stdio.h>
#include <vector>
#include <climits>

using namespace std;

const unsigned long REMAINDER = 1000000007;

unsigned long long Combination(int n, int k) {
	int divided[100], divisor[100];
	unsigned long long res =1;
	unsigned long long divNum = 1;

	for(int i=n, j=1; i>n-k; --i, ++j){
		divided[j-1] = i;
		divisor[j-1] = j;
	}

	for(int i=0; i<k; ++i){
		for(int j=0; j< k; j++){
			if((divisor[j] != 0) && 
				((divided[i]%divisor[j]) == 0) ){
				int tmp = divided[i];
				divided[i]/=divisor[j];
				divisor[j] =0;
			}
		}
	}

	for(int i=0; i<k; ++i)
		if(divisor[i] !=0) divNum *=divisor[i];

	for(int i =0; i<k; ++i)
		if( res < ULLONG_MAX)
			res *= divided[i];
		

	res=(res / divNum); //%REMAINDER;
	printf("%llu       dfsdf\n",res);

	return res;
}

int main() {

	int C,n;
	vector<unsigned long long> out;

	scanf("%d",&C);

	for (int i = 0; i < C; ++i) {
		scanf("%d",&n);

		int row2 = n / 2;
		int col1 = n % 2;
		unsigned long long res = 0;

		res = res + Combination(col1 + row2
			, col1 < row2 ? col1 : row2);

		int tmp = row2;
		for(int j=0; j< row2; ++j){
			--tmp;
			col1+=2;
			res = res + Combination(col1+tmp
					, col1 < tmp ? col1 : tmp );//)% REMAINDER;
		}

		printf("%llu          ==",res);

		res %=REMAINDER;
		out.push_back(res);
	}

	for(int i=0; i<out.size(); ++i)
		printf("%llu\n",out[i]);

	return 0;
}