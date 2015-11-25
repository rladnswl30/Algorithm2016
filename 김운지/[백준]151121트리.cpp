#include <stdio.h>

int arr[100] = {};
int gragh[100][100] = {};
int visited[100] = {};
int num = 0;
int leaf = 0;
int del = 0;

void dfs(int k) {
	visited[k] = 1;
	//printf("%d ", k);
	bool flag = false;
	for (int i = 1; i <= num; i++) {
		if (gragh[k][i] == 1 && visited[i] == 0) {
			dfs(i);
			flag = true;
		}
	}
	if (!flag) leaf++;
}

int main(void) {
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
		gragh[0][0] = 1;
		if (arr[i] == -1) {
			arr[i] = -1;
		}
		else {
			gragh[arr[i]][i] = gragh[i][arr[i]] = 1;
		}
	}

	scanf("%d", &del);

	for (int i = 0; i < num; i++) {
		gragh[i][del] = gragh[del][i] = 0;
	}

	for (int j = 1; j < num; j++){
		if (arr[j] == -1) {
			num = j;
		}
	}

	
	/*출력*/
	//printf("\n");
	//printf("arr[i] : ");
	//for (int i = 0; i < num; i++) {
	//	printf("%d ", arr[i]);
	//}
	//printf("\n");


	//printf("gragh[i][j] : \n");
	//for (int i = 0; i < num; i++) {
	//	for (int j = 0; j < num; j++) {
	//		printf("%d ", gragh[i][j]);
	//	}
	//	printf("\n");
	//}
	/*출력*/

	dfs(0);

	if (gragh[0][0] == 0) {
		leaf = 0;
	}


	//printf("leaf : \n");
	printf("%d\n", leaf);
}
