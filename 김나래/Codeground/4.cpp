// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <cstdio>
#include <iostream>
#include <math.h>

using namespace std;

const double PI = 3.141592;

inline int getCoordi(int x, int y){
	if(x>0 && y>0) return 0; // 1사분면
	if(x<0 && y>0) return 1; // 2사분면
	if(x<0 && y<0) return 2; // 3사분면
	if(x>0 && y<0) return 3; // 4사분면
	return -1;
}

int main(int argc, char** argv) {
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	   그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	//freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;
	int coordi[4][5]={{6,13,4,18,1,},{20,5,12,9,14},{11,8,16,7,19},{3,17,2,15,10}};
	// 기울기
	double slope = { 0, tan((9/180)*PI), tan((27/180)*PI), tan((45/180)*PI), tan((63/180)*PI), tan((81/180)*PI) };
	enum S{ BULL=0, DOUBLE_S, DOUBLE_E, TRIPLE_S, TRIPLE_E};
    
	scanf("%d", &TC);	// cin 사용 가능
	for(test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.
        int score[5],N, sum = 0, c;
        
        for(int i=0; i< 5; ++i)
        	cin >> score[i];
        cin >> N;

        for(int i=0; i< N; ++i){
        	int x,y, res;
        	cin >> x >> y;
        	int radius2 = x*x + y*y; 
        	double grad = y/x;

        	if((c=getCoordi(x,y)) == 1 || c ==3){
        		for(int i=1; i<=5; ++i){
        			if(slope[i-1] < grad && grad < slope[i]){
        				res = coordi[c][i];
        				break;
        			}
        		}
        	} else{
        		for(int i=5; i>0; --i){
        			if(slope[i] < grad && grad < slope[i-1]){
        				res = coordi[c][i];
        				break;
        			}
        		}
        	}

        	if( radius2 <= score[S.BULL] ) sum += 50;
        	else if(radius2 <= score[S.DOUBLE_S]) sum+=res;
        	else if(radius2 <= score[S.DOUBLE_E]) sum = res * 2;
        	else if(radius2 <= score[TRIPLE_S]) sum+=res;
        	else if(radius2 <= score[TRIPLE_E) sum = 3;
        	else continue;       	
        }

		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);	// cout 사용 가능
        cout << sum << endl;
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}