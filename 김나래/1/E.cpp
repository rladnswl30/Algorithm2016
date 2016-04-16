#include <iostream>
#include <string>

using namespace std;

int main(){
	string m;
	string n = "JENNIFERSOFT";
	cin >> m;

	string res="";

	for(int i=0; i< m.size(); ++i){
		for(int j=0; j< n.size(); ++j){
			if(m[i] == n[j])
				res+=m[i];
		}
	}

	cout << res << endl;

	return 0;
}