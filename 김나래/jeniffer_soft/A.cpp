#include <iostream>
#include <vector>

using namespace std;

typedef struct Alpha{
	char c;
	int count;
	bool operator < (const Alpha r) const {return count <r.count; } 
}Alpha;

int main(){

	vector<Alpha> cnt(26);
	string s;

	for(int i=0; i< 26;++i)
		cnt[i].count = 0;
	cin >> s;

	for(int i=0; i< s.size(); ++i){
		int idx = s[i]-'A';
		cnt[idx].c = s[i];
		cnt[idx].count++;
	}

	sort(cnt.begin(), cnt.end());

	int i=0;
	while(cnt[i].count == 0){ ++i;}
	for(int k =i; k< 26; ++k){
		for(int j=0; j < cnt[k].count; ++j)
			cout << cnt[k].c;
	}

	return 0;
}