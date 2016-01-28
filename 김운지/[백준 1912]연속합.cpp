#include <stdio.h>

int d[100001];
int a[100001];

int main(void) {
	int n = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++) {
		//이전 까지 더한거
		d[i] = d[i - 1] + a[i];
		//새로운 값이 이전에 더한것보다 클 경우
		if (a[i] > d[i - 1] + a[i]) {
			d[i] = a[i];
		}
		
	}
	
	int max = d[0];
	for (int i = 0; i < n; i++) {
		if (max < d[i]) {
			max = d[i];
		}
	}

	printf("%d\n", max);
	return 0;
}


/*
#include <stdio.h>

int d[100001];
int a[100001];

int main(void) {
	int n = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++) {
	
		d[i] = a[i];	//새로운 연속 합

		//i-1번째 수를 포함하는 연속합이 더 클 경우
		if (d[i] < d[i - 1] + a[i]) {
		d[i] = d[i - 1] + a[i];
		}

	}

	int max = d[0];
	for (int i = 0; i < n; i++) {
		if (max < d[i]) {
			max = d[i];
		}
	}

	printf("%d\n", max);
	return 0;
}
*/