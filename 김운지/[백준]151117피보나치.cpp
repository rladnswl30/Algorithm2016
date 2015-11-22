#include <stdio.h>
#include <string.h>

int zero = 0;
int one = 0;
int i = 0;

int fibonacci(int n) {
	if (n == 0) {
		//printf("0");
		zero++;
		//printf("zero : %d\n", zero);
		return 0;
	}
	else if (n == 1) {
		//printf("1");
		one++;
		//printf("one : %d\n", one);
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main(void) {
	int a;
	int num;
	scanf("%d", &a);

	while (a--) {
		scanf("%d", &num);
		fibonacci(num);
		printf("%d %d\n", zero, one);
		zero = 0;
		one = 0;
	}

	return 0;
}