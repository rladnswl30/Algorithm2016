#include <iostream>
#include <set>
#include <map>
#include <numeric>

using namespace std;

typedef set<Point> POINT_SET;
typedef POINT_SET::iterator sIter;
typedef POINT_SET::iterator const_sIter;


typedef set<POINT_SET> POLY_SET;
typedef POLY_SET::iterator psIter;

typedef map<const int, Polyominos> POLY_TABLE;


// Point 클래스 : 정사각형의 위치를 알려주는 좌표 클래스
class Point{		
private:
	int x;
	int y;

public:
	Point() : x(0), y(0){}
	Point(int _x, int _y) : x(_x), y(_y){}
	~Point(){}

	int getX() const {return x;}	// getter
	int getY() const {return y;}	

	void set(Point p){				// setter
		x=p.getX();
		y=p.getY();
	}

	void add ( Point a , Point b) {
		x = a.getX() + b.getX());
		y = b.getY() + b.getY());
	}

	// 순서관계 정의 => x가 작은 것 부터 , 만약 x가 같다면 y가 작은거부터 정렬한다.
	bool operator<(const Point &a){		
		 if(x < a.getX())
		 	return true;
		 else if (x == a.getX())
		 	if(y < a.getY()) return true;
		 	else return false;
		 else
		 	return false;
	}

	// x좌표와 y좌표가 같으면 두 Point는 같다.
	bool operator==(const Point &a){	
		return (x == a.getX()) && 
				(y == a.getY());
	}
};

// Shape 클래스 : 정사각형 집합 , polyomise 도형 하나
class Shape{
private:
	POINT_SET m_shape;

public:
	Shape(){}
	~Shape(){}

	const_sIter begin() const {return m_shape.begin();}
	const_sIter end() const {return m_shape.end();}

	void add(POINT_SET origPosSet, Point newPos){
		m_shape.insert(origPosSet.begin(), origPosSet.end());
		m_shape.insert(newPos);
	}

	// 도형 shape를 이동시키는 함수
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

		// trans 좌표를 가지고 모든 도형을 원점으로 이동 
		Point res;
		for(int i=0;i<size;i++){
			res.add(orig[i],trans);
			m_shape.insert(res);
		}
	}
	// 순서관계 결정 
	bool operator<(const POLY_SHAPE &b){
		return (m_shape.begin()->getX() < b.begin()->getX());
	}

	// == 정의
	bool operator==(const POLY_SHAPE &b){
		for(sIter i = m_shape.begin();  i != m_shape.end(); ++i){
			for(iterator j = b.begin();  j != b.end(); ++j){
				if( (*i) != (*j))	// 포지션이 다른 하나만 있어도 다름.
					return false;
			}
		}
		// 함수가 완벽히 정렬되 있어야 함.
		return true;
	}
};


class Polyominos{
private:
	POLY_SET 	nowSet; 
	int 		num;

	static Point dxdy[4];	// 방향정보
	const int DIR_SIZE;

public:

	POLY_SET makePossibleShape(POLY_SET preSet){
		Point newLoc;
		POINT_SET newShape;
		//const_sIter
		for( psIter it = preSet.begin; 
				it != preSet.end(); ++it){

			for( sIter c_it = it->begin();
					c_it != it->end(); ++c_it){

				for(int i=0; i<DIR_SIZE; i++){
					newPos.add(*c_it, dxdy[i]);
					newShape.add(*it,newPos);
					nowSet.insert(newShape);
				}
			}	
		}

		return nowSet;
	}

	Polyominos(int n) : num(n), DIR_SIZE(4) {
		dxdy[0] = Point(-1,0);
		dxdy[1] = Point(1,0);
		dxdy[2] = Point(0,-1);
		dxdy[3] = Point(0,1);  
	}

	~Polyominos(){}

};



int main(){

	// 입력부
	int nTest;
	int tests[50];
	POLY_TABLE tbl;    // 정사각형 테이블

	// 입력
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
	POLY_SET polySet;

	for(int i=0; i<nTest; i++){
		for(int n=1; n<tests[i]+1; n++){
			if(tbl.count(n) < 0)
				polySet = accumulate(tbl.begin(),tbl.end(),makePossibleShape);
			tbl.insert(n,polySet);
			printf("%dn",polySet.size());
		}
	}

	return 0;	
}
