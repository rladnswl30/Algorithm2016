//
/*#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int num;
	int dt;

	int x1, y1, r1, x2, y2, r2;
	scanf("%d", &num);

	for (int x = 0; x < num; x++) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		dt = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); //거리

		//중점이 같은 경우
		if (dt == 0) {
			if (r1 == r2) {	//똑같은 원
				printf("-1\n");
			}
			else {			//원 안에 원이 들어갔을 때
				printf("0\n");
			}
		}

		//중점이 다른 경우
		else if (dt == ((r1 + r2) * (r1 + r2))) {	//외접
			printf("%d\n", 1);
		}
		else if (dt == ((r1 - r2) * (r1 - r2))) {	//내접
			printf("%d\n", 1);
		}
		else if (dt > ((r1 + r2) * (r1 + r2))) {	//외부
			printf("%d\n", 0);
		}
		else if (dt < ((r1 - r2) * (r1 - r2))) {	//내부
			printf("%d\n", 0);
		}
		else {
			printf("%d\n", 2);
		}
	}
}*/