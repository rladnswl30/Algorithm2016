#include <iostream>

using namespace std;

int main(){

	int N, count =0;
	string seat[1000];
	cin >> N;
	
	for(int i=0; i< N; ++i)
		cin >> seat[i];

	for(int i=0; i< N; ++i)
		for(int j=0; j< N; ++j)
			if(j+1 < N && seat[i][j] == '.' && seat[i][j+1] == '.')
				count++;

	cout << count << endl;
	return 0;
}