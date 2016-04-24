#include <crtdbg.h>
#include <iostream>

using namespace std;

struct Base {
public:
	int val1;
	int val2;
	Base(int v1, int v2) : val1(v1), val2(v2) {}
};

template<typename T>
class SharePtr {
private:
	T* data;	// ������
	int refcnt;	// ���۷��� ī��Ʈ

public:
	SharePtr() : data(NULL), refcnt(1) {}			// ����Ʈ ������
	SharePtr(T* _data) : data(_data), refcnt(1) {}	// ������ ������ �ޱ�

	SharePtr(const SharePtr& rhs) {	// ���������
		data = rhs.data;			// ����� rhs�� ������ ����
		refcnt = rhs.refcnt + 1;	// ����� rhs �� ���۷��� ī��Ʈ�� �ڽ��� ī��Ʈ�� �߰��� �� ����
	}

	~SharePtr() {				// �Ҹ��� �Լ�
		if (--refcnt == 0) {	// ���۷��� ī��Ʈ�� 0�� ���� �����͸� �����Ѵ�
			delete data;
			data = NULL;
		}
	}

	inline int GetRefCount() { return refcnt; }		// ���۷��� ī��Ʈ�� ��ȯ �Լ�

	T* const operator->() const { return data; }	// -> ���� ������ �����ε�
	T const operator*() const { return *data; }		// * ������ ������ �����ε� 
};


void Test1() {
	SharePtr<Base> p(new Base(10, 20));
	int i = p->val1 + (*p).val2;
	cout << i << endl;
	_ASSERTE(i == 30);
}

void Test2() {
	SharePtr<Base> p1(new Base(10, 20));
	{
		SharePtr<Base> p2 = p1;
		_ASSERTE(p2.GetRefCount() == 2);
	}
	_ASSERTE(p1.GetRefCount() == 1);
}

int main() {

	Test1();
	Test2();

	return 0;
}