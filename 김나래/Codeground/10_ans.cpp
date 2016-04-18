#include <stdio.h>
int N;
char d[1001][1001];
int check[1001][1001];
//'0', '1', '2' : 빔,/,
//동서남북, 0 1 2, tx,ty
int refx[4][3]={{1,0,0},{-1,0,0},{0,-1,1},{0,1,-1}};
int refy[4][3]={{0,-1,1},{0,1,-1},{1,0,0},{-1,0,0}};
int refdir[4][3]={{0,3,2},{1,2,3},{2,1,0},{3,0,1}};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void init() {
	int i,j;
	for(i=0;i<N;i++) for(j=0;j<N;j++) check[i][j]=0;
}
int range(int y, int x) {
	if(y>=0 && y<N && x>=0 && x<N) return 1;
	return 0;
}
int main(void) {
	int i,j,k,y,x;
	int TC;
	int test_case;

	setbuf(stdout, NULL);

	
	scanf("%d", &TC);
	for(test_case = 1; test_case <= TC; test_case++) { 
        scanf("%d",&N);
		for(i=0;i<N;i++) {
			for(j=0;j<N;j++) {
				scanf(" %c",&d[i][j]);
			}
		}
        init();
		int dap=0;
		int dir=0; //동서남북 0123
		int x=0,y=0;
		int tx,ty,tdir;
		while(1) {
			if(!range(y,x)) break;
			else {
				if(!check[y][x] && (d[y][x]=='1' || d[y][x]=='2')) {
					dap++;
					check[y][x]=1;
				}
				tx=x+refx[dir][d[y][x]-'0'];
				ty=y+refy[dir][d[y][x]-'0'];
				tdir=refdir[dir][d[y][x]-'0'];
				x=tx;
				y=ty;
				dir=tdir;
			}
		}

		printf("Case #%d\n", test_case);
		printf("%d\n",dap);
	}

	return 0;
}