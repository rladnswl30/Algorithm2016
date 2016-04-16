/*
최대 힙
https://www.acmicpc.net/problem/11279

푸는 중
*/

#include <iostream>

using namespace std;

inline int Parent(int i) { return (i - 0.5) / 2; }
inline int Left(int i) { return 2 * i; }
inline int Right(int i) { return 2 * i + 1; }

void Max_Heapify(int(&A)[100000], int i, int heapSize) {
	int largest = 0;
	int l = Left(i);
	int r = Right(i);

	if (l <= heapSize && A[l] > A[i])
		largest = l;
	else
		largest = i;

	if (r <= heapSize && A[l] > A[largest])
		largest = r;

	if (largest != i) {
		int tmp = A[i];			// swap
		A[i] = A[largest];
		A[largest] = i;
		Max_Heapify(A, largest, heapSize);
	}
}

int main() {
	int heap[100000], N, x, heapSize = 0;
	fill(&heap[0], &heap[0] + sizeof(heap), 0);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> x;
		if (x == 0) {
			cout << heap[0] << endl;
			heap[0] = 0;
		}
		else
			Max_Heapify(heap, x, heapSize);
	}

	return 0;
}

/*
테스트케이스

13 0 1 2 0 0 3 2 1 0 0 0 0 0
답 : 0 2 1 3 2 1 0 0
*/