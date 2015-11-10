#include <stdio.h>
//
//int main(void) {
//	int c, i;
//	unsigned int n, res;
//
//	scanf("%d", &c);
//
//	for (i = 0; i < c; i++) {
//		scanf("%d", &n);
//
//		res = ((n & 255) << 24) + ((n & (255 << 8)) << 8)
//			+ ((n & (255 << 16)) >> 8) + ((n & (255 << 24)) >> 24);
//	
//		printf("%u\n", res);
//	
//	}
//}
////
//int main(void) {
//	int n;
//	int i;
//	int x1, x2, x3;
//	int y1, y2, y3;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &x1);
//		scanf("%d", &y1);
//		scanf("%d", &x2);
//		scanf("%d", &y2);
//		scanf("%d", &x3);
//		scanf("%d", &y3);
//
//		printf("%d %d\n", x1^x2^x3, y1^y2^y3);
//
//
//	}
//
//	return 0;
//}


int main(void) {
	int array[7] = { 64, 32, 16, 8, 4, 2, 1 };
	int count = 1;
	int a = 0;

	scanf("%d", &a);

	for (int i = 0; i < 7; i++) {
		if (array[i] == a) printf("%d\n", count);
		else if (array[i] < a) {
			for (int j = 1; j < 7; j++) {
				if (a > array[i] + array[j]) {
					array[i] = array[i] + array[j];
					count++;
				}
				else if (array[i] > a)
					continue;
				else if (a == array[i] + array[j]) {
					printf("%d\n", count);
					count++;
					return 0;
				}
			}
		}
	}
	return 0;
}