#include <stdio.h>

bool isHansu(int num) {
	int n1, n2, n3;

	n1 = num / 100;
	n2 = (num / 10) % 10;
	n3 = num % 10;

	if (n2 == 0) return false;
	else if ((n1 + n3) / 2 == n2 && (n1 + n3) % 2 == 0)
		return true;
	else return false;
}

int main(void) {
	int n;
	int cnt = 0;

	scanf("%d", &n);

	for (int i = n; i >= 1; i--) {
		if (i < 100)
			cnt++;
		else if (isHansu(i)) {
			cnt++;
		}
	}

	printf("%d\n", cnt);
}