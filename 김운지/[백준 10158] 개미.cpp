/*
#include <stdio.h>

int main()
{
	int w, h, x, y, t;
	int result_x, result_y;

	scanf("%d %d", &w, &h);
	scanf("%d %d", &x, &y);
	scanf("%d", &t);

	if ((x + t) / w % 2 == 0)
		result_x = (x + t) % w;
	else
		result_x = w - (x + t) % w;

	if ((y + t) / h % 2 == 0)
		result_y = (y + t) % h;
	else
		result_y = h - (y + t) % h;

	printf("%d %d\n", result_x, result_y);

	return 0; 
}
*/

#include <stdio.h>

int main(void){
	int w, h;
	int x, y;
	int dx = 1;
	int dy = 1;
	long t;

	scanf("%d %d", &w, &h);
	scanf("%d %d", &x, &y);
	scanf("%d", &t);

	while (t--){
		// ��, �� ���� �ε����� ���
		if (x == w || x == 0)
			dx =- dx;
		// ��, �� ���� �ε����� ���
		if (y == h || y == 0)
			dy =- dy;
		//printf("dx dy : %d %d\n", dx, dy);
		// �ٽ��� if ~ else if �� �ƴ϶�
		// if ~ if�� �����ν� 
		// �������� �ε��� ��쵵 �ش��� ��.
		x += dx;
		y += dy;

		//printf("x y : %d %d\n", x, y);
	}
	printf("%d %d", x, y);
}