#include <iostream>
#include <set>

using namespace std;

typedef struct {
}Pos;



class Pos{
private:
	int x;
	int y;

public:
	void set(Pos p){
		x=p.x;
		y=p.y;
	}

	int getX(){return x;}
	int getY(){return y;}

};

class Polyomino{
private:

	typedef set<Pos>::iterator iterator;
	set<shape> poly;
	set<Pos> shape;	// 포인트 들의 집합
	Point min = {0,0};

	bool resetPosition(set<Pos> shape){

		min.set(shape[0]);

		getX;
		getY;

		for(int i=1; i<shape.size; i++){
			if(min.x > shape[i].x)
				min.x = shape[i].x;
			if(min.y > shape[i].y)
				min.y = shape[i].y;
		}

		min.x *= (-1);
		min.y *= (-1);

		for(int i=0; i< shape.size; i++)
			shape[i].set(min)
	}

public:
	Polyomino(int n){
		Point base = {0,0};
		Point newP = {0,0};

		for(int i=0; i<4; i++){
			newP.x = base.x + dxdy[i].x;
			newP.y = base.y + dxdy[i].y;
			shape.insert(newP);
			poly.insert(shape);
		}
	}

};


int main(){

	// 입력부
	int nTest;
	int tests[50];
	map<int,Polyomino> poly;


	while(1){
		cin >> nTest;

		if(nTest>= 1 && nTest <=50)
			break;
		else
			cout << "테스트 케이스는 1-50 사이만 허용" <<endl;
	}

	for(int i=0;i<nTest;i++)
		cin >> tests[i]);

	// 폴리오미오 개수 세기.
	Point base ={0,0};


	for(int i=0; i<nTest; i++){
		for(int n=1; n<tests[i]+1< n++){
			poly.insert(Polyomino(n));

		}
	}

	return 0;	
}
