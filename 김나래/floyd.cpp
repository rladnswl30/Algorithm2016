#include <stdio.h>

void floyd(int n)   
{  

    int i, j, k; 
    for(i=0; i<n; i++) 
        for(j=0; j<n; j++) 
            A[i][j]=weight[i][j]; 

        for(k=0; k<n; k++){ 
        for(i=0; i<n; i++) 
               for(j=0; j<n; j++) 
                  if (A[i][k]+A[k][j] < A[i][j]) 
                     A[i][j] = A[i][k]+A[k][j]; 
                printA(n); 
        } 
}

int main(){

  int N,M;
  int Arr[100][100]={0,};

  scanf("%d %d", &N , &M);

  for(int i=0; i<N;++i){
    for(int j=0; j<N;++j){
        scanf("%d",Arr[i][j]);
    }
  }

  floyed()

  return 0;
}