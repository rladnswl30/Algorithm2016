/*
2015.11.16
https://www.acmicpc.net/problem/1009
제출했는데 오답이라 나옴 / 왜그런것인지?!
*/

#include <stdio.h>

int main(){

	int T=0;
	int a=0,b=0;
	unsigned long res;
	
	scanf("%d",&T);
	for(int i=0; i<T; ++i){
		scanf("%d %d",&a,&b);
		res =1;

		for(int i=0; i<b;i++)
			res=(res*a)%10;

		printf("%lu\n",res);
	}

	return 0;
}