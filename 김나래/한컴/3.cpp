#include <string.h>
#include <stdio.h>

class Collection {
private:
	int* m_A;
	int m_Count;
	int m_Pos;

public:
	Collection(int count) {
		if (!m_A) {
			m_A = new int[count];
		}
		m_Count = count;		// 동적할당된 배열 사이즈를 저장해야함
		m_Pos = 0;				// m_Pos 현재까지 값이 채워진 배열 인덱스
	}
	~Collection(){
		if(!m_A){				// 소멸자 호출 시 메모리 해제 코드 삽입
			delete [] m_A;
		}
	}
	void Add(int val) {
		if (m_Count < m_Pos) {
			Glow(m_Count + m_Count / 2);
		}
		m_A[m_Pos] = val;
		++m_Pos;
	}

	void Print(){
		printf("m_A[%d]=%d \n", m_Pos-1, m_A[m_Pos-1]);
	}

private:
	void Glow(int count) {
		int* reAlloc = new int[count];
		memcpy(reAlloc, m_A, count *sizeof(int));
		delete [] m_A;			// 메모리 누수를 방지하기 위한 해제코드 삽입 
		m_A = reAlloc;
		m_Count = count;
	}
};

int main(){
	Collection c(3);

	for(int i =1; i< 5+1; ++i){
		c.Add(i);
		c.Print();
	}

	return 0;
}