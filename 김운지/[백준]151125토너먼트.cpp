#include <stdio.h>

int main(void) {
	int num = 0;
	int result = 0;
	int rest = 0;
	int a, b = 0;

	scanf("%d %d %d", &num, &a, &b);

	//b>a

	if (b > a) {
		//¦��(������ ����)
		if (num % 2 == 0) {
			//������ ��
			if (b == a + 1 && b % 2 == 0) {
				result = 1;
			}
			//�������� ���� ��
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

		//Ȧ��(������ ����)
		else if (num % 2 == 1) {
			//������ ��
			if (b == a + 1 && b % 2 == 0) {
				result = 1;
			}
			//�������� ���� ��
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
		//¦��(������ ����)
		if (num % 2 == 0) {
			//������ ��
			if (a == b + 1 && a % 2 == 0) {
				result = 1;
			}
			//�������� ���� ��
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

		//Ȧ��(������ ����)
		else if (num % 2 == 1) {
			//������ ��
			if (a == b + 1 && a % 2 == 0) {
				result = 1;
			}
			//�������� ���� ��
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