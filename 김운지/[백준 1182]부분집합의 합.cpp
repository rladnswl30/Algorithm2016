#include <stdio.h>

int n = 0;
int s = 0;
int input[20];
int cnt = 0;

void dfs(int index, int sum);

int main(void) {
	//N(�Է��� ������ ����), S(��ü�� ��) �Է��ϱ�
	scanf("%d %d", &n, &s);

	//N���� input�� �Է��ؼ� input�迭�� �ֱ�
	for (int i = 0; i < n; i++) {
		scanf("%d", &input[i]);
	}

	//0~N���� ���̿켱Ž�� ����
	for (int i = 0; i < n; i++) {
		dfs(i, input[i]);
		printf("****************************\n");
	}

	//ī��Ʈ ���
	printf("%d\n", cnt);
	return 0;
}

//���̿켱Ž��
void dfs(int index, int sum) {
	//���� ���� S�� ���ٸ� ī��Ʈ�� �÷��ش�.
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



printf("*****Main��\n");
printf("%d, ", i);
printf("%d\n", input[i]);

//	printf("@@@@COUNT ����!!!\n");

printf("*************DFS�Լ�\n");
printf("%d, ", i);
printf("%d\n", sum + input[i]);
printf("\n");

*/