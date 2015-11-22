/*
2015.11.16
https://www.acmicpc.net/problem/1009
*/

#include <stdio.h>

int main(){

	int T=0;
	int a=0,b=0;
	int res;
	
	scanf("%d",&T);
	for(int i=0; i<T; ++i){
		scanf("%d %d",&a,&b);
		res =1;

		for(int i=0; i<b;i++)
			res=(res*a)%10;

		if (res == 0) printf("10\n");
		else printf("%d\n",res);
	}

	return 0;
}