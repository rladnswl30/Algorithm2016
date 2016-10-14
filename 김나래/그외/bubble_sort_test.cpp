#include <iostream>

using namespace std;

int main(){
	int tmp=0;
	bool swapped= true;
	int arr[10] = {52,33,27,3,4,1,99,44,29,43};
	for(int i=0; i< 10; ++i){

		for(int p=0; p < 10; ++p)
			cout << arr[p] << (p != 9 ? ", " : " ");
		cout << "swapped ["<< swapped << "]"<<endl;

		swapped = true;

		for(int j = 9; j >= i+1 && swapped; --j){
			if(arr[j] < arr[j-1]){
				tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
				swapped = true;
			}
		}
	}
	return 0;
}

/*
1, 3, 4, 27, 29, 33, 43, 44, 52, 99


*/