#include <iostream>

using namespace std;

// 수정 전 
/* 
int Sum(int start, int last) {
	int* a = new int[last - start];			// 1. 할당된 메모리가 해제되지 않음, a 가 필요 없음
	int sum = 0;
	for (int i = start; i <= last; ++i) {
		a[i] = i;
	}
	for (int i = start; i <= last; ++i) {
		sum += a[i];
	}
	return sum;
}

*/

// 수정 후
inline int Sum(const int start, const int last) {
	int sum = 0;
	for (int i = start; i <= last; ++i) {
		sum += i;
	}

	return sum;
}

int main() {
	
	cout << Sum(1, 5) << endl;

	int a = 2, b = 4;
	cout << Sum(a, b) << endl;

	return 0;
}