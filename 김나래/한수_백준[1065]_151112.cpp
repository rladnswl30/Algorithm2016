#include <stdio.h>

int main() {
	int N;
	while (1) {
		scanf("%d", &N);

		if (N > 0 && N <= 1000) break;
		else printf("1 에서 1000 사이 자연수를 입력하세요.");

		fflush(stdin);
	}

	int cnt = 0;
	for (int i = 1; i < N; ++i) {
		int k = 1, n = i;
		int a1, d, an_1, an;
		
		while (n > 0) {
			if (k == 1) {
				a1 = n % 10;
				if ((n / 10) == 0) ++cnt;
			} else if (k == 2) {
				an = n % 10;
				d = an - a1;
				if ((n / 10) == 0)++cnt;
			}else {
				an_1 = an;
				an = n % 10; //나머지
				if (d == (an - an_1)) ++cnt;
				else break;
			}
			n /= 10;
			++k;
		}
	}

	printf("%d\n", cnt);

	return 0;

}