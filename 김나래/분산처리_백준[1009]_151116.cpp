/*
2015.11.16
https://www.acmicpc.net/problem/1009
제출했는데 오답이라 나옴 / 왜그런것인지?!
*/

#include <stdio.h>
#include <vector>

using namespace std;

int modulo(int a, int b){
	int cache[11]={-1,};
	int i=0;
	unsigned long long res = 1;

	while(1){
		res = (res*a)%10;
		if(cache[1] != res){
			cache[i] = res;
			//printf("cache[%d] = %llu\n",i,res);
			++i;
		} else 
			break;
	}

	int idx;
	printf("i == %d",i);
	if((idx=b%(i-1) )==0)
		idx = i-2;
	printf("idx : %d\n",idx);
	//printf("b mod size = %d: %d mod %d , cache[b mod size] : %d\n",b%size, b, size, cache[b%size]);

	return cache[idx];
}

int main(){

	int T=0;			// 테스트 케이스
	int a=0,b=0;
	vector<unsigned long long> res;
	
	scanf("%d",&T);
	for(int i=0; i<T; ++i){
		scanf("%d %d",&a,&b);

		int k=modulo(a,b);
		//puts("7");
		res.push_back(k);
		//puts("8");			
	}

	for(int i=0; i<res.size(); ++i)
		printf("%llu\n",res[i]);

	return 0;
}