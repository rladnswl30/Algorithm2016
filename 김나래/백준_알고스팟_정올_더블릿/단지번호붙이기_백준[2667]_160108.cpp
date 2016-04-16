/*
20160108
단지번호붙이기 백준
채점성공
테스트 케이스

7
0110100
0110101
1110101
0000111
0100000
0111110
0111000

답 : 
3
7
8
9

7
0110100
0110001
1110101
0000111
0100000
0111110
0111001
답:
5
1
1
6
7
9

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int bfs(string*& arr,int N, int i, int j, int cnt) {
	arr[i][j] = '0';
	if (i+1 < N  && arr[i+1][j] == '1') cnt += bfs(arr,N, i+1, j, 1);
	if (i-1 > -1 && arr[i-1][j] == '1') cnt += bfs(arr,N, i-1, j, 1);
	if (j+1 < N  && arr[i][j+1] == '1') cnt += bfs(arr,N, i, j+1, 1);
	if (j-1 > -1 && arr[i][j-1] == '1') cnt += bfs(arr,N, i, j-1, 1);
	return cnt;
}
int main() {
	vector<int> res;
	string c;

	getline(cin, c);
	int N = stoi (c);
	string* arr = new string[N];
	
	for (int i = 0; i < N; ++i)
		getline(cin, arr[i]);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (arr[i][j] == '1')
				res.push_back(bfs(arr,N,i,j,1));

	cout << res.size() << endl;
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;

	return 0;
}