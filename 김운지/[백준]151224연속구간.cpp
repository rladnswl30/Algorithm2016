#include <stdio.h>

int main(void) {
	

	//3���� ���� �Է��� �� ����
	for (int k = 0; k < 3; k++) {
		int strcnt[9];
		char str[9];
		/*�ʱ�ȭ*/
		int cnt = 1;
		int max = 1;

		for (int i = 0; i < 8; i++) {
			strcnt[i] = 1;
			str[i] = '\0';
		}
		/*******/

		//8�ڸ� �Է�
		scanf("%s", str);

		for (int i = 0; i < 8; i++) {
			//������ ���ڰ� ���� ���
			if (str[i] == str[i + 1]) {
				cnt++;
				//printf("������ ���ڰ� ���� ���\n");
				//printf("cnt : %d\n", cnt);
			}

			//������ ���ڰ� �ٸ� ���
			else {
				strcnt[i] = cnt;
				//printf("������ ���ڰ� �ٸ� ���\n");
				//printf("strcnt[%d] : %d\n", i, cnt);
				cnt = 1;
			}
		}
		
		//strcnt�迭 �� ū �� ���
		max = strcnt[0];
		for (int i = 0; i < 8; i++) {
			if (max < strcnt[i]) {
				max = strcnt[i];
			}
		}

		//printf("\n");

		for (int i = 0; i < 8; i++) {
			//printf("strcnt[%d] : %d\n", i, strcnt[i]);
		}
		
		printf("%d\n", max);
	}
}
