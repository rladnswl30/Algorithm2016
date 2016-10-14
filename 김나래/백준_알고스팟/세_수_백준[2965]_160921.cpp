/*
<조합>
세 수 [2965]
https://www.acmicpc.net/problem/2985

채점 성공
*/
#include <iostream>

using namespace std;

enum{PLUS=0, MINUS, MULT, DIV, EQUAL};

int main(){
	int nums[3];
	char op;

	for(int i=0; i<3; ++i)
		cin >> nums[i];

	int res =0, res1=nums[0];

	for(int i=1; i >=0; --i){  // + - 숫자 개수 
		res = (i == 1)? nums[0] : nums[2];
			
		for(int operType=0; operType < 4; ++operType){
			switch(operType){
			case PLUS:
				op = '+';
				res1 = nums[i]+nums[i+1]; break;
			case MINUS:
				op = '-';
				res1 = nums[i]-nums[i+1]; break;
			case MULT:
				op = '*';
				res1 = nums[i]*nums[i+1]; break;
			case DIV:
				op = '/';
				res1 = nums[i]/nums[i+1]; break;
			}
			if(res == res1){
				if(i == 1){
					cout << nums[0] << "=" << nums[1] << op << nums[2] << endl; 
				} else{
					cout << nums[0] << op << nums[1] << "=" << nums[2] << endl;
				}
				return 0;
			}
		}

	}

	return 0;
}