#include <stdio.h>

int main(void) {
	int T;
	int test_case;
	int a, b = 0;
	unsigned long long c = 1;
	int result = 1;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++) {
		result = 1;
		scanf("%d %d", &a, &b);

		for (int i = 0; i < b; i++) {
			result = result * a;
			result = result % 10;
			if (result == 0) {
				result = 10;
			}
		}

		printf("%d\n", result);
	}

}