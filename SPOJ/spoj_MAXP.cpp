#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <vector>
#include <algorithm>
#define f(i,x,y) for(int i=x; i<y; i++)
using namespace std;

#define MAX 250
int matrix[MAX][MAX];
int acum[MAX][MAX];

int binary(int n,int r int i, int j){
	int m;
	while(i<j){
		m = (l+r)/2;
		if(acum[r][m]==n)
			break;
		else if(n<=acum[r][m])
			r = m;
		else
			r = m+1;
	}
	return i;
}

int main(){
	int n, m, a, b;
	scanf("%d%d",&n,&m);
	f(i,0,n)
		f(j,0,m){
		scanf("%d",&matrix[i][j]);
		acum[i][j]=matrix[i][j];
		}
	scanf("%d%d",&a,&b);
	f(i,0,n)
		f(j,0,m){
			if(i) acum[i][j] += acum[i-1][j];
			if(j) acum[i][j] += acum[i][j-1];
			if(i&&j) acum[i][j] -= acum[i-1][j-1];
		}
	//solve
	f(i,0,n)
		f(j,0,m){
			
		}
	return 0;
}
