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
	T* data;	// 데이터
	int refcnt;	// 레퍼런스 카운트

public:
	SharePtr() : data(NULL), refcnt(1) {}			// 디폴트 생성자
	SharePtr(T* _data) : data(_data), refcnt(1) {}	// 데이터 포인터 받기

	SharePtr(const SharePtr& rhs) {	// 복사생성자
		data = rhs.data;			// 복사될 rhs의 데이터 저장
		refcnt = rhs.refcnt + 1;	// 복사될 rhs 의 레퍼런스 카운트에 자신의 카운트를 추가한 뒤 저장
	}

	~SharePtr() {				// 소멸자 함수
		if (--refcnt == 0) {	// 레퍼런스 카운트가 0일 때만 데이터를 삭제한다
			delete data;
			data = NULL;
		}
	}

	inline int GetRefCount() { return refcnt; }		// 레퍼런스 카운트를 반환 함수

	T* const operator->() const { return data; }	// -> 참조 연산자 오버로딩
	T const operator*() const { return *data; }		// * 역참조 연산자 오버로딩 
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