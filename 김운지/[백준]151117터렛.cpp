#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int num;
	int dt;

	int x1, y1, r1, x2, y2, r2;
	scanf("%d", &num);

	for (int x = 0; x < num; x++) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		dt = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); //�Ÿ�

		//������ ���� ���
		if (dt == 0) {
			if (r1 == r2) {	//�Ȱ��� ��
				printf("-1\n");
			}
			else {			//�� �ȿ� ���� ���� ��
				printf("0\n");
			}
		}

		//������ �ٸ� ���
		else if (dt == ((r1 + r2) * (r1 + r2))) {	//����
			printf("%d\n", 1);
		}
		else if (dt == ((r1 - r2) * (r1 - r2))) {	//����
			printf("%d\n", 1);
		}
		else if (dt > ((r1 + r2) * (r1 + r2))) {	//�ܺ�
			printf("%d\n", 0);
		}
		else if (dt < ((r1 - r2) * (r1 - r2))) {	//����
			printf("%d\n", 0);
		}
		else {
			printf("%d\n", 2);
		}
	}
}