/*
면접에 늦었다 백준

https://www.acmicpc.net/problem/5014

채점 성공
greedy 솔루션 

*/

#include <iostream>

using namespace std;

int main(){
	int f, s, g, u,d;
	cin >> f >> s >> g >> u >> d;
	int sum = s;
	int count =0;

	while(1){
		if( sum > g ) {
			if( d == 0 ){
				cout << "use the stairs" << endl;
				return 0;
			}
			if( sum -g >= d){
				int num = (sum-g)/d;
				sum -= num * d;
				count += num;
			} else{
				if(u >= d){
					cout << "use the stairs" << endl;
					return 0;
				}
				int num = (sum - g)/(d-u);
				sum -= num*(d-u);
				count += (num*2);

				if(sum != g ){
					cout << "use the stairs" << endl;
					return 0;
				} else
					break;
			}
		} else if (sum < g){
			if(u == 0){
				cout << "use the stairs" << endl;
				return 0;
			}
			if( g - sum >= u ){
				int num = (g - sum)/u;
				sum += (num*u);
				count += num;
			} else {
				if( d >= u){
					cout << "use the stairs" << endl;
					return 0;
				}
				int num = (g-sum) / (u-d);
				sum += num*(u-d);
				count += (num*2);

				if(sum != g ){
					cout << "use the stairs" << endl;
					return 0;
				} else
					break;
			}
		} else
			break;
	}

	cout << count << endl;

	return 0;
}