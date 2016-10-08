#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct Alpha {
	char	c;			// 알파벳 대문자
	int		count;		// 해당 문자 빈도수
	// 연산자 오버로딩 함수 sort 시 count 값으로 정렬
	bool operator < (const Alpha r) const { return count <r.count; }
}Alpha;

int main() {

	vector<Alpha> cnt(26);			// 알파벳 개수 26 만큼 저장
	string s;						// 입력받을 문자열

	for (int i = 0; i < 26; ++i) {	// 초기화
		cnt[i].c = 'A' + i;			// 대문자 초기화
		cnt[i].count = 0;			// 빈도수 초기화
	}

	getline(cin, s);				// 문자열 입력 받기

	for (int i = 0; i< s.size(); ++i)
		cnt[s[i] - 'A'].count++;	// 인덱스 빈도수 증가

	sort(cnt.begin(), cnt.end());	// 정렬

	int i = 0;
	while (cnt[i].count == 0) { ++i; }	// 정렬 후 쓰인 알파벳 위치 찾기

	for (int k = i; k< 26; ++k)
		for (int j = 0; j < cnt[k].count; ++j)
			cout << cnt[k].c;		// 출력

	return 0;
}