/* 2015.11.14
*  algospot Ÿ�ϸ� ����
* https://algospot.com/judge/problem/read/TILING2
* nrkim
* 100�� ����� �ȳ���
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

unsigned long long Combination(int n, int k) {
	const unsigned long REMINDER = 1000000007;
	unsigned long long a = 1, r = 1;
	int i, j=1, tt=0;

	for(i =n; i >=n-k; --i){
		a *= i;
		r *= j;
		j++;
	}
	
	return (a / r)% REMINDER;

}


int main() {

	int C;		// C : �׽�Ʈ ���̽�
	while (1) {
		cin >> C;
		if (C <= 50) break;
		else cout << "�׽�Ʈ ���̽��� 50�� ���Ϸ� �Է�." << endl;
	}

	int* nArr = new int[C];	// nArr : ���� n ��� �迭
	for (int i = 0; i < C;) {
		int n;				// n : ����
		cin >> n;
		if (n >= 1 && n <= 100) {
			nArr[i] = n;
			++i;
		}
		else
			cout << "���� 100������ �ڿ����� �Է�." << endl;
	}


	for (int i = 0; i < C; ++i) {
		int row2 = nArr[i] / 2;
		int col1 = nArr[i] % 2;
		BigInt res(0);

		res += Combination(col1 + row2, col1);

		int rowTmp = row2;
		for (int j = 0; j < row2; ++j) {
			--rowTmp;
			col1 += 2;

			res += Combination(col1 + rowTmp
				, col1 < rowTmp ? col1 : rowTmp);
		}

		cout << res << endl;
		//res.print();
	}

	delete[] nArr;

	return 0;
}