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
		//���� ���� ���Ѱ�
		d[i] = d[i - 1] + a[i];
		//���ο� ���� ������ ���Ѱͺ��� Ŭ ���
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
	
		d[i] = a[i];	//���ο� ���� ��

		//i-1��° ���� �����ϴ� �������� �� Ŭ ���
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