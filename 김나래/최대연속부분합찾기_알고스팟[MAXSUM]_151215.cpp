/*
�ִ� ���� �κ��� ã��
�˰���
https://algospot.com/user/profile/18914

ä�� ����

�׸��� ���
*/
#include <iostream>

using namespace std;

int maxSum(int*& arr, int N) {
	int max = 0;
	int pre = 0;

	for (int i = 0; i < N; ++i) {
		if (pre + arr[i] < 0) {
			pre = 0;
			continue;
		}
		pre += arr[i];
		if (max < pre) max = pre;
	}

	return max;
}


int main() {
	int T, N;

	cin >> T;

	for (int t = 0; t< T; ++t) {
		cin >> N;
		int* arr = new int[N];
		for (int n = 0; n < N; ++n)
			cin >> arr[n];

		cout << maxSum(arr, N) << endl;

		delete[] arr;
	}

	return 0;
}

/*
�׽�Ʈ ���̽�

4
1 2 3 4
�� : 10

3
-1 0 1
�� : 1

6
4 10 2 -10 2 3
�� : 16

10
-2 -1 0 1 2 3 4 -1 7 8
�� : 24

8
2 -6 4 5 -2 6 2 -1
�� : 15

6
-3 -2 0 1 -4 -3
�� : 1

*/