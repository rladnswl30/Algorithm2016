#include <iostream>
#include <vector>
#include <list>

using namespace std;

// ���׸� �ڷ��� T �� ���׸� �ݺ��� iter ���ø� ����
template <typename T, typename Iter>

// STL �����̳� Ŭ���� ��Ҹ� ���ϴ� Sum �Լ�
// begin : �ݺ��� ����, end : �ݺ��� ��, init : �ʱⰪ
T Sum(Iter begin, Iter end, T init) {
	T result = init;

	// �ݺ��ڸ� �̿��� ��� ���ϱ� �Լ�
	for (Iter it = begin; it != end; ++it) {
		result += *it;
	}

	return result;
}

int main() {

	vector<int> intVals{ 0,1,2 };	// int �� ���� ���� 
	list <float> floatVals{ 0.F, 1.2F, 2.7F }; // float�� ����Ʈ ����

	// ���� ���ֹ��� �ʴ� ���ϱ� �Լ�
	int intTotal = Sum(intVals.begin(), intVals.end(), 0);
	float floatTotal = Sum(floatVals.begin(), floatVals.end(), 0.0);

	cout << intTotal << endl;
	cout << floatTotal << endl;

	return 0;
}