#include <stdio.h>

int main(void) {
	

	//3개의 숫자 입력할 수 있음
	for (int k = 0; k < 3; k++) {
		int strcnt[9];
		char str[9];
		/*초기화*/
		int cnt = 1;
		int max = 1;

		for (int i = 0; i < 8; i++) {
			strcnt[i] = 1;
			str[i] = '\0';
		}
		/*******/

		//8자리 입력
		scanf("%s", str);

		for (int i = 0; i < 8; i++) {
			//연속한 숫자가 같을 경우
			if (str[i] == str[i + 1]) {
				cnt++;
				//printf("연속한 숫자가 같은 경우\n");
				//printf("cnt : %d\n", cnt);
			}

			//연속한 숫자가 다를 경우
			else {
				strcnt[i] = cnt;
				//printf("연속한 숫자가 다를 경우\n");
				//printf("strcnt[%d] : %d\n", i, cnt);
				cnt = 1;
			}
		}
		
		//strcnt배열 중 큰 값 출력
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
