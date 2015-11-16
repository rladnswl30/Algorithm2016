#include <stdio.h>

int main(void) {

	int a;
	int n = 0;
	int r = 0;
	unsigned long long resh = 1;
	unsigned long long resl = 1;
	unsigned long long result = 1;

	scanf("%d", &a);

	while (a--) {

		resh = 1;
		resl = 1;
		result = 1;

		scanf("%d %d", &r, &n);

		if (n == r) {
			result = 1;
		}

		else { //r < n
			if (n / 2 < r) {
				r = n - r;
			}

			for (int i = 1; i <= r; i++) {
				resh = resh * i;
				//printf("resh : %llu\n", resh);
			}

			for (int j = n - r + 1; j <= n; j++) {
				resl = resl * j;
				//printf("resl : %llu\n", resl);
			}

			//printf("resh, resl : %llu %llu\n", resh, resl);
			result = resl / resh;

		}

		printf("%llu\n", result);
	}
}