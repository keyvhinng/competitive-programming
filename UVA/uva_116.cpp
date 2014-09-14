#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cmath>
#include <cassert>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i=x; i<y; i++)
#define FOR(it,A) for(typeof A.begin(); it!=A.end(); it++)
#define quad(x) (x)*(x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second

#define MAX 2147483647


typedef long long ll;
typedef pair<int,int> pii;

int m[10][100];
int DP [10][100];
int DP_U [10][100];
int pathX[10][100];
int pathY[10][100];

int R, C;

int cmpPath(int x2, int y2, int x1, int y1){
	int ans;
	ans = 0;
	while(pathX[x1][y1]!=-1){
		if(pathX[x2][y2]<pathX[x1][y1]){
			ans = 1;
			break;
		}
		x1 = pathX[x1][y1];
		y1 = pathY[x1][y1];
		x2 = pathX[x2][y2];
		y2 = pathY[x2][y2];
	}
	return ans;
}

int run(int r, int c){
	int ans, min, indx, nr;
	if(DP_U[r][c]!=-1){
		return DP[r][c];
	}
	if(c==C-1){
		DP_U[r][c] = 1;
		DP[r][c] = m[r][c];
		pathY[r][c] = -1;
		pathX[r][c] = -1;
		return DP[r][c];
	}
	pathY[r][c] = c+1;
	min = MAX;
	//
	nr = (r+1)%R;
	ans = m[r][c] + run(nr, c+1);
	min = ans;
	pathX[r][c] = nr;
	indx = nr;
	//printf("=at %d %d\n",r,c);
	//printf("first nr is %d\n",nr);
	//printf("with %d\n",ans);
	//
	nr = r;
	ans = m[r][c] + run(nr, c+1);
	//printf("=at %d %d\n",r,c);
	//printf("second nr is %d\n",nr);
	//printf("recibe min %d\n",min);
	//printf("ans = %d\n",ans);
	if(ans<=min){
		if(ans==min){
			if(indx>nr){
				pathX[r][c] = nr;
				indx = nr;
			}
		}else{
			pathX[r][c] = nr;
			min = ans;
			indx = nr;
			//printf("min changes to %d\n",min);
		}
	}
	//
	nr = r-1;
	if(nr<0){ 
		nr = R-1;
	}
	ans = m[r][c] + run(nr, c+1);
	//printf("=at %d %d\n",r,c);
	//printf("recibe index %d\n",indx);
	//printf("third nr is %d\n",nr);
	//printf("with %d\n",ans);
	if(ans<=min){
		if(ans==min){
			if(indx>nr){
				pathX[r][c] = nr;
				indx = nr;
			}
		}else{
			pathX[r][c] = nr;
			min = ans;
		}
	}
	DP_U[r][c] = 1;
	//printf("min return with %d\n",min);
	return DP[r][c] = min;
}

int main(){
	int min, ans, flag;
	int x1, y1, x2, y2, indx;
	while(scanf("%d %d",&R, &C)==2){
		f(i,0,R){
			f(j,0,C){
				scanf("%d",&m[i][j]);
				DP_U[i][j] = -1;
			}
		}
		min = MAX;
		f(i,0,R){
			ans = run(i,0);
			if(ans<min){
				indx = i;
				min = ans;
			}
		}
		x1 = indx;
		y1 = 0;
		printf("%d",indx + 1);
		while(pathX[x1][y1]!=-1){
			printf(" %d",pathX[x1][y1] + 1);
			x1 = pathX[x1][y1];
			y1 = pathY[x1][y1];
		}
		printf("\n");
		printf("%d\n",min);
	}
	return 0;
}
