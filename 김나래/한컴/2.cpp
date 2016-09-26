#include <iostream>

using namespace std;

// ���� �� 
/* 
int Sum(int start, int last) {
	int* a = new int[last - start];			// 1. �Ҵ�� �޸𸮰� �������� ����, a �� �ʿ� ����
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

// ���� ��
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