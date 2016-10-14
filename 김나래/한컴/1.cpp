#include <iostream>
#include <vector>
#include <list>

using namespace std;

// 제네릭 자료형 T 와 제네릭 반복자 iter 템플릿 선언
template <typename T, typename Iter>

// STL 컨테이너 클래스 요소를 더하는 Sum 함수
// begin : 반복자 시작, end : 반복자 끝, init : 초기값
T Sum(Iter begin, Iter end, T init) {
	T result = init;

	// 반복자를 이용한 요소 더하기 함수
	for (Iter it = begin; it != end; ++it) {
		result += *it;
	}

	return result;
}

int main() {

	vector<int> intVals{ 0,1,2 };	// int 형 백터 선언 
	list <float> floatVals{ 0.F, 1.2F, 2.7F }; // float형 리스트 선언

	// 형에 구애받지 않는 더하기 함수
	int intTotal = Sum(intVals.begin(), intVals.end(), 0);
	float floatTotal = Sum(floatVals.begin(), floatVals.end(), 0.0);

	cout << intTotal << endl;
	cout << floatTotal << endl;

	return 0;
}