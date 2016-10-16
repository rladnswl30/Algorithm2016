/*
1번

시간 복잡도 O(N)
공간복잡도 O(1)

*/
#include <iostream>

void solution(int N) {
	// write your code in C++11 (g++ 4.8.2)

	for (int n = 1; n <= N; ++n) {
		bool flag = true;
		if (n % 3 == 0) {
			cout << "Fizz";
			flag = false;
		}
		if (n % 5 == 0) {
			cout << "Buzz";
			flag = false;
		}

		if (n % 7 == 0) {
			cout << "Woof";
			flag = false;
		}

		if (flag)
			cout << n;
		cout << endl;
	}
}

int main() {
	int N;
	cin >> N;
	solution(N);

	return 0;
}