#include <stdio.h>

int n = 0;
int s = 0;
int input[20];
int cnt = 0;

void dfs(int index, int sum);

int main(void) {
	//N(입력할 숫자의 갯수), S(전체의 합) 입력하기
	scanf("%d %d", &n, &s);

	//N까지 input값 입력해서 input배열에 넣기
	for (int i = 0; i < n; i++) {
		scanf("%d", &input[i]);
	}

	//0~N까지 깊이우선탐색 시작
	for (int i = 0; i < n; i++) {
		dfs(i, input[i]);
		printf("****************************\n");
	}

	//카운트 출력
	printf("%d\n", cnt);
	return 0;
}

//깊이우선탐색
void dfs(int index, int sum) {
	//만약 합이 S와 같다면 카운트를 올려준다.
	if (sum == s) {
		cnt++;
	}

	for (int i = index + 1; i < n; i++) {
		printf("dfs(i, sum + input[i] : %d, %d\n", i, sum + input[i]);
		dfs(i, sum + input[i]);
	}
}


/*
		//printf("dfs(i, sum + input[i] : %d, %d\n", i, sum + input[i]);



printf("*****Main문\n");
printf("%d, ", i);
printf("%d\n", input[i]);

//	printf("@@@@COUNT 증가!!!\n");

printf("*************DFS함수\n");
printf("%d, ", i);
printf("%d\n", sum + input[i]);
printf("\n");

*/