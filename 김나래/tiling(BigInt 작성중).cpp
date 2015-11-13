/* 2015.11.14
*  algospot 타일링 문제
* https://algospot.com/judge/problem/read/TILING2
* nrkim
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Big Int -> 100 의 조합을 계산하기위한 큰 정수 객체 
class BigInt {
private:
	const unsigned long ATOM = 1000000007;
	typedef vector<long long> ::iterator iterator;

private:
	vector<long long> integer;

public:
	BigInt() { integer.insert(integer.begin(), 0); }
	BigInt(int n) { integer.insert(integer.begin(), n); }

	long long at(int i) const { return integer[i]; }

	BigInt& operator *=(const int& num) {
		int carry = 0;

		for (int i = 0; i < integer.size(); ++i) {
			integer[i] = integer[i] * num + carry;
			carry = integer[i] / ATOM;

			if (carry)
				integer[i] %= ATOM;
		}
		if (carry)
			integer.insert(integer.end(), carry);

		return *this;
	}

// b는 반드시 더 작은 수임
//friend
BigInt&  operator += (const BigInt& b) {
	int minSize, maxSize;
	bool small = false;

	if (integer.size() >= b.integer.size()) {
		minSize = b.integer.size();
		maxSize = integer.size();
	}else {
		minSize = integer.size();
		maxSize = b.integer.size();
		small = true;
	}

	int carry = 0;
	int i;
	for ( i= 0; i < minSize; ++i) {
		integer[i] = integer[i] + b.at(i) + carry;
		carry = integer[i] / ATOM;

		if (carry)
			integer[i] %= ATOM;
	}

	if (small) {
		iterator it = integer.end();
		for (int j = i; j < maxSize; j++) {
			integer.insert(it, b.integer[j]+carry);
			carry = 0;
		}
	}

	return *this;
}

BigInt operator/(const BigInt& b) {

	int carry=0;

	for (int i = integer.size() - 1; i >= 0; --i) {
		long long dividend = integer[i];     carry*ATOM + ;
		long long divisor = b.at(0);
		long long quotient = dividend / divisor;


		carry = dividend % divisor;
	}

	return *this;
}

void print(){
	for (int i = 0; i < integer.size(); ++i)
		cout << integer[i];
	cout << endl;
}

};

unsigned long long Combination(int n, int k) {
	const unsigned long REMINDER = 1000000007;
	unsigned long long a = 1, r = 1;
	int i, j=1, tt=0;

	for(i =n; i >=n-k; --i){
		a *= i;
		r *= j;
		j++;
	}
	
	unsigned long long res = a / r; //디버깅
	return res% REMINDER;

}


int main() {

	int C;		// C : 테스트 케이스
	while (1) {
		cin >> C;
		if (C <= 50) break;
		else cout << "테스트 케이스는 50개 이하로 입력." << endl;
	}

	int* nArr = new int[C];	// nArr : 정수 n 담는 배열
	for (int i = 0; i < C;) {
		int n;				// n : 정수
		cin >> n;
		if (n >= 1 && n <= 100) {
			nArr[i] = n;
			++i;
			//continue;
		}
		else
			cout << "숫자 100이하의 자연수로 입력." << endl;
	}


	for (int i = 0; i < C; ++i) {
		int row2 = nArr[i] / 2;
		int col1 = nArr[i] % 2;
		BigInt res(0);
		//unsigned long long res = 0;

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