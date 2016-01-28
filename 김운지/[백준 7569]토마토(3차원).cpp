#include <stdio.h>
//bfs
int queue[10000000] = {};
int front, rear = 0;
int arr[105][105][205] = {};

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
	int m, n, h = 0;
	int temp = 0;
	int x, y, z = 0;
	int max = 0;
	int result = 0;

	//M * N * H �Է¹ޱ�
	scanf("%d", &m);
	scanf("%d", &n);
	scanf("%d", &h);

	//-2�� ���
	for (int k = 0; k < h + 2; k++) {
		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < m + 2; j++) {
				arr[k][i][j] = -2;
			}
		}
	}

	//�� ���� �Է¹ޱ�
	for (int k = 1; k < h + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				scanf("%d", &arr[k][i][j]);
			}
		}
	}

	/*���
	printf("\n");
	for (int k = 0; k < h + 2; k++) {
		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < m + 2; j++) {
				printf("%3d ", arr[k][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	/*****/
	

	for (int k = 1; k < h + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				if (arr[k][i][j] == 1) {
					enqueue(k * 10000000 + i * 10000 + j);
				}
			}
		}
	}

	while (!isempty()) {
		temp = dequeue();

		x = temp / 10000000;
		y = (temp % 10000000) / 10000;
		z = (temp % 10000000) % 10000;

		temp = arr[x][y][z];

		//��
		if (arr[x - 1][y][z] == 0) {
			arr[x - 1][y][z] = temp + 1;
			enqueue((x - 1) * 10000000 + y * 10000 + z);
		}

		//�Ʒ�
		if (arr[x + 1][y][z] == 0) {
			arr[x + 1][y][z] = temp + 1;
			enqueue((x + 1) * 10000000 + y * 10000 + z);
		}

		//��
		if (arr[x][y - 1][z] == 0) {
			arr[x][y - 1][z] = temp + 1;
			enqueue(x * 10000000 + (y - 1) * 10000 + z);
		}

		//��
		if (arr[x][y + 1][z] == 0) {
			arr[x][y + 1][z] = temp + 1;
			enqueue(x * 10000000 + (y + 1) * 10000 + z);
		}

		//��
		if (arr[x][y][z - 1] == 0) {
			arr[x][y][z - 1] = temp + 1;
			enqueue(x * 10000000 + y * 10000 + (z - 1));
		}

		//��
		if (arr[x][y][z + 1] == 0) {
			arr[x][y][z + 1] = temp + 1;
			enqueue(x * 10000000 + y * 10000 + (z + 1));
		}
	}

	/*���
	printf("\n");
	for (int k = 0; k < h + 2; k++) {
		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < m + 2; j++) {
				printf("%3d ", arr[k][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	/*****/
	

	//max�� ���ϱ�
	max = arr[1][1][1];
	for (int k = 1; k < h + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				if (max < arr[k][i][j]) {
					max = arr[k][i][j];
				}
				result = max - 1;

				//��� ��������� -1 = ��� -1�̸� -1
				if (max == -1) {
					result = -1;
				}
			}
		}
	}
	//printf("max : %d\n", max);

	//�ϳ��� �� �;����� -1
	for (int k = 1; k < h + 1; k++) {
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				if (arr[k][i][j] == 0) {
					result = -1;
				}
			}
		}
	}

	printf("%d\n", result);
	return 0;
}