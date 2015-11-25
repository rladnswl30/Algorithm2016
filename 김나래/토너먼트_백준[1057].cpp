/*
20151126
https://www.acmicpc.net/problem/1057
채점 성공
*/

#include <stdio.h>

int main(){

	int N, Kim, Lim, cnt=0;

	scanf("%d %d %d", &N, &Kim, &Lim);

	while(Kim != Lim ){
		if( N == 0 ){
			cnt = -1;
			break;	
		}
		N  = (N %2 == 0)? N/2 : N/2+1;
		Kim = (Kim%2 == 0) ? Kim/2 : Kim/2+1;
		Lim = (Lim%2 == 0) ? Lim/2 : Lim/2+1;
		cnt++;
	}

	printf("%d\n",cnt);

	return 0;
}