#include <stdio.h>

int main(){
	int X=0;
	int cnt=0;

	while(1){
		scanf("%d", &X);

		if(X>=0 && X<65) break;
		else printf("X cannot be more than 64. try again.\n");

		fflush(stdin);
	}

	// 이진수에서 1의 개수가 막대로 만들 수 있는 수
	while(X !=0){
		if((X % 2)> 0) cnt++;	
		X /=2;
	}

	printf("%d\n",cnt);

	return 0;
}