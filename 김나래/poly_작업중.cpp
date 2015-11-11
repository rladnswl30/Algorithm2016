#include <iostream>
#include <set>
#include <map>

using namespace std;

class Point{		// 정사각형의 위치를 알려주는 좌표 클래스
private:
	int x;
	int y;

public:
	Point() : x(0), y(0){}
	Point(int _x, int _y) : x(_x), y(_y){}
	~Point(){}

	int getX() const {return x;}	// getter
	int getY() const {return y;}	

	void set(Point p){				// 사칙연산 setter
		x=p.getX();
		y=p.getY();
	}

	// static 함수
	void add ( Point a , Point b) {

		x = a.getX() + b.getX());
		y = b.getY() + b.getY());

	}

	bool operator<(const Point &a){		// 순서관계 정의 => 순서관계 정하는거 자세히 알아보기
		 if(x < a.getX())
		 	return true;
		 else 
		 	return false;
	}

	bool operator==(const Point &a){	// x좌표와 y좌표가 같으면 두 Point는 같다.
		return (x == a.getX()) && 
				(y == a.getY());
	}
};

// 정사각형 집합 , polyomise 도형 하나
class Shape{
private:
	set<Point> m_shape;

public:
	typedef set<Point> 			POLY_SHAPE;
	typedef Shapes::iterator 	iterator;

	Shape(){}
	~Shape(){}

	void transform(Point &orig, int size){
		// 가장 왼쪽 x좌표와 가장 아래쪽 y좌표를 구함
		int minX = orig[0].getX();
		int minY = orig[0].getY();
		for(int i=0; i<size; i++){
			if( minX > orig[i].getX())
				minX  = x;

			if( minY > orig[i].getY())
				minY = y;
		}

		Point trans(-minX,-minY);

		//0 점으로 이동 
		Point res;
		for(int i=0;i<size;i++){
			res.add(orig[i],trans);
			m_shape.insert(res);
		}
	}
	// order 결정 
	bool operator<(const POLY_SHAPE &b){
		return (m_shape.begin()->getX() < b.begin()->getX());
	}

	// 순서관계가 정확하게 맞아야함. 
	// 순서관계 만드는 법 알아보기 
	bool operator==(const POLY_SHAPE &b){
		for(iterator i = m_shape.begin();  i != m_shape.end(); ++i){
			for(iterator j = b.begin();  j != b.end(); ++j){
				if( (*i) != (*j))	// 포지션이 다른 하나만 있어도 다름.
					return false;
			}
		}
		// 완벽히 일치해야 함.
		return true;

	}
};


class Polyominos{
private:
	typedef set<POLY_SHAPE> POLY_SET;
	typedef POLY_SET::iterator iter;

	POLY_SET set; 

	int num;
public:

	POLY_SET makePossibleShape(POLY_SET set){
		set

	}

	Polyominos(int n) : num(n) {}
	~Polyominos(){}

};


typedef map<const int, Polyominos> POLY_TABLE;

int main(){

	// 입력부
	int nTest;
	int tests[50];
	POLY_TABLE tbl;    // 정사각형 테이블


	while(1){
		cin >> nTest;

		if(nTest>= 1 && nTest <=50)
			break;
		else
			cout << "테스트 케이스는 1-50 사이만 허용" <<endl;
	}

	for(int i=0;i<nTest;i++)
		cin >> tests[i];

	// 폴리오미오 개수 세기.
	Point base(0,0);

	for(int i=0; i<nTest; i++){
		for(int n=1; n<tests[i]+1; n++){
			poly.insert(Polyomino(n));

		}
	}

	return 0;	
}
