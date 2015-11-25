
#include <stdio.h>


int main(){

	int N, Kim, Lim;
	int cnt=0;

	scanf("%d %d %d", &N, &Kim, &Lim);

	while(N !=1){
		N  = (N %2 == 0)? N/2 : N/2+1;
		Kim = (Kim%2 == 0) ? Kim/2 : Kim/2+1;
		Lim = (Lim%2 == 0) ? Lim/2 : Lim/2+1;
		cnt++;
	}

	printf("%d\n",cnt);

	return 0;
}