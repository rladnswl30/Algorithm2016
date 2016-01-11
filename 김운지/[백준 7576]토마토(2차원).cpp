#include <stdio.h>
//bfs
int queue[10000000] = {};
int front, rear = 0;
int arr[1005][1005] = {};

void enqueue(int a) {
	queue[rear++] = a;
}

int dequeue() {
	return queue[front++];
}

bool isempty() {
	if (front == rear) {
		return true;
	}
	else {
		return false;
	}
}

int main(void) {
	int m = 0;
	int n = 0;
	int temp = 0;
	int x, y = 0;
	int max, min = 0;
	int result = 0;

	//M * N �Է¹ޱ�
	scanf("%d", &m);
	scanf("%d", &n);

	//-2�� ���
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < m + 2; j++) {
			arr[i][j] = -2;
		}
	}

	//�� ���� �Է¹ޱ�
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	/*���
	printf("\n");
	for (int i = 0; i < n + 2; i++) {
	for (int j = 0; j < m + 2; j++) {
	printf("%3d ", arr[i][j]);
	}
	printf("\n");
	}
	/******/


	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (arr[i][j] == 1) {
				enqueue(i * 10000 + j);
			}
		}
	}

	while (!isempty()) {
		temp = dequeue();

		x = temp / 10000;
		y = temp % 10000;

		temp = arr[x][y];

		//��
		if (arr[x - 1][y] == 0) {
			arr[x - 1][y] = temp + 1;
			enqueue((x - 1) * 10000 + y);
		}

		//�Ʒ�
		if (arr[x + 1][y] == 0) {
			arr[x + 1][y] = temp + 1;
			enqueue((x + 1) * 10000 + y);
		}

		//��
		if (arr[x][y - 1] == 0) {
			arr[x][y - 1] = temp + 1;
			enqueue(x * 10000 + (y - 1));
		}

		//��
		if (arr[x][y + 1] == 0) {
			arr[x][y + 1] = temp + 1;
			enqueue(x * 10000 + (y + 1));
		}
	}

	/*���
	printf("\n");
	for (int i = 0; i < n + 2; i++) {
	for (int j = 0; j < m + 2; j++) {
	printf("%3d ", arr[i][j]);
	}
	printf("\n");
	}
	/******/


	//max�� ���ϱ�
	max = arr[1][1];
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (max < arr[i][j]) {
				max = arr[i][j];
			}
			result = max - 1;

			//��� ��������� -1 = ��� -1�̸� -1
			if (max == -1) {
				result = -1;
			}
		}
	}
	//printf("max : %d\n", max);

	//�ϳ��� �� �;����� -1
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (arr[i][j] == 0) {
				result = -1;
			}
		}
	}

	printf("%d\n", result);
	return 0;
}
