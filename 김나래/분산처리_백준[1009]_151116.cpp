/*
2015.11.16
https://www.acmicpc.net/problem/1009
제출했는데 오답이라 나옴 / 왜그런것인지?!
*/

#include <stdio.h>

long long modulo(int a, int b) {
	long long cache[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	int i = -1, idx;
	long long res = 1;

	// cache[0]번은 쓰지 않음
	while (cache[0] != (res = (res*a) % 10)) {
		cache[++i] = res;
	}

	if ((idx = (b % (i + 1)) - 1) < 0)
		idx = i;

	return cache[idx];
}

int main(){

	int T=0;			// 테스트 케이스
	int a=0,b=0;
	
	scanf("%d",&T);
	for(int i=0; i<T; ++i){
		scanf("%d %d",&a,&b);

		printf("%lld\n", modulo(a, b));
	}

	return 0;
}