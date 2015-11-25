#include <stdio.h>

int main(void) {
	int num = 0;
	int result = 0;
	int rest = 0;
	int a, b = 0;

	scanf("%d %d %d", &num, &a, &b);

	//b>a

	if (b > a) {
		//짝수(부전승 없음)
		if (num % 2 == 0) {
			//연속할 때
			if (b == a + 1 && b % 2 == 0) {
				result = 1;
			}
			//연속하지 않을 때
			else {
				//printf("1: %d \n", num);
				while (rest == 0) {
					num = num / 2;
					rest = num % 2;
					//printf("2: %d \n", num);
					result++;
				}
			}
		}

		//홀수(부전승 있음)
		else if (num % 2 == 1) {
			//연속할 때
			if (b == a + 1 && b % 2 == 0) {
				result = 1;
			}
			//연속하지 않을 때
			else {			
				result = 1;
				printf("1: %d \n", num);
				while (rest == 0) {
					num = num / 2;
					rest = num % 2;
					printf("2: %d \n", num);
					result++;
					printf("result : %d\n", result);
				}
			}
		}
	}

	//a>b

	else if (a > b) {
		//짝수(부전승 없음)
		if (num % 2 == 0) {
			//연속할 때
			if (a == b + 1 && a % 2 == 0) {
				result = 1;
			}
			//연속하지 않을 때
			else {
				//printf("1: %d \n", num);
				while (rest == 0) {
					num = num / 2;
					rest = num % 2;
					//printf("2: %d \n", num);
					result++;
				}
			}
		}

		//홀수(부전승 있음)
		else if (num % 2 == 1) {
			//연속할 때
			if (a == b + 1 && a % 2 == 0) {
				result = 1;
			}
			//연속하지 않을 때
			else {
				result = 1;
				while (rest == 0) {
					num = num / 2;
					rest = num % 2;
					//printf("2: %d \n", num);
					result++;
				}
			}
		}
	}

	printf("%d\n", result);
}