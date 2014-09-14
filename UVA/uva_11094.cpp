#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <ctime>

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
#define sz size

using namespace std;

char m[20][20], l, w;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int M, N;

int dfs(int x, int y){
	int nx, ny, ans;
	m[x][y] = w;
	ans = 1;
	f(i,0,4){
		nx = x + dx[i];
		ny = (y + dy[i] + N)%N;
		if(nx>=0 && nx<M && m[nx][ny]==l) ans += dfs(nx,ny);
	}
	return ans;
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	char c;
	int x, y, max, r, flag;
	while(scanf("%d%d",&M,&N)==2){
		getchar();
		f(i,0,M){
			f(j,0,N) scanf("%c",&m[i][j]);
			getchar();
		}
		scanf("%d%d",&x,&y);
		l = m[x][y];
		flag = 1;
		for(int i=0; i<M && flag; i++)
			for(int j=0; j<N && flag; j++){
				if(m[i][j]!=l){
					w = m[i][j];
					flag = 0;
				}
			}
		dfs(x,y);
		max = 0;
		f(i,0,M){
			f(j,0,N){
				if(m[i][j]==l){
				    r =  dfs(i,j);
					max = max<r?r:max;
				}
			}
		}
		printf("%d\n",max);
	}
	return 0;
}

