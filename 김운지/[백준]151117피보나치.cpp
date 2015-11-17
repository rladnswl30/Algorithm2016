#include <stdio.h>
#include <string.h>

char str[100];
char str2[100];
int zero = 0;
int one = 0;
int i = 0;

int fibonacci(int n) {
	if (n == 0) {
		str[i] = '1';
		i++;
		//printf("0");
		return 0;
	}
	else if (n == 1) {
		str2[i] = '2';
		i++;
		//printf("1");
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}

}

int main(void) {
	int a;
	int num;
	int zero = 0;
	int one = 0;
	scanf("%d", &a);

	while (a--) {
		int zero = 0;
		int one = 0;
		memset(str, 0, sizeof(str));
		memset(str2, 0, sizeof(str2));

		scanf("%d", &num);
		fibonacci(num);
		for (int i = 0; i < 100; i++) {
			if (str[i] == '1') {
				zero++;
				//printf("zero : %d\n", zero);
			}
			else if (str2[i] == '2') {
				one++;
				//printf("one : %d\n", one);
			}
		}
		printf("%d %d\n", zero, one);
	}

	return 0;
}