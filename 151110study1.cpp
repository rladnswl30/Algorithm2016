#include <stdio.h>

int main(void) {
	int array[7] = { 64, 32, 16, 8, 4, 2, 1 };
	int cnt = 1;
	int input = 0;

	scanf("%d", &input);

	for (int i = 0; i < 7; i++) {
		if (array[i] == input) {		//입력한거랑 array 같을때
			printf("%d\n", cnt);
		}

		else if (array[i] > input)		//입력한게 array보다 작을때
			continue;

		else if (array[i] < input) {	//입력한게 array보다 클때
			for (int j = i+1; j < 8; j++) {
				if (input > array[i] + array[j]) {
					array[i] = array[i] + array[j];
					cnt++;
				}

				else if (input < array[i] + array[j]) {
					continue;
				}
				
				else if (input == array[i] + array[j]) {
					cnt++;
					printf("%d\n", cnt);
					return 0;
				}

			}
		}
	}
	return 0;
}