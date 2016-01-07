#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int res[3];

	for(int l=0; l<3; ++l){
		int max[8]={0}, cnt=1,maxCnt=0;
		string str;
		getline(cin,str);
		for(int i=0; i<8; ++i){
			if((i+1 <8) && str[i] == str[i+1])
				cnt++;
			else{
				max[i] = cnt;
				cnt =1;
			}
		}
		for(int i=0;i<8;++i){
			if(maxCnt < max[i])
				maxCnt = max[i];
		}
		res[l] = maxCnt;
	}

	for(int i=0; i< 3; ++i)
		cout<<res[i]<<endl;

	return 0;
}