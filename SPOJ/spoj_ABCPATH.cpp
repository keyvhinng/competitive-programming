#include <algorithm>
#include <bitset>
#include <deque>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
#define clr(a, v) memset(a, v, sizeof(a))
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define REPN(i,s,n) for(int i=s;i<(int)(n);i++)
#define REP(i,n) REPN(i,0,n)
#define REPIT(i,x) for( typeof x.begin()  i=x.begin(); i!=x.end(); i++ )
#define trace(x)    cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;

using namespace std;

typedef long long int64;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <string> vs;
typedef vector <ii> vii;

const int INF = 2e9+9;

vector<string> mat;

int h, w, tmp;

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
int vis[60][60];

void dfs(int x, int y, int d){
	vis[x][y] = 1;
	int nx, ny;
	tmp = max(tmp,d);
	REP(i,8){
		nx = x + dx[i];
		ny = y + dy[i];
		if(nx>=0 && nx<h && ny>=0 && ny<w && !vis[nx][ny]){
			if(mat[x][y]+1==mat[nx][ny]){
				dfs(nx,ny,d+1);
			}
		} 
	}
	return;
}

int main(){
	string s;
	int nc = 1;
	while(scanf("%d%d",&h,&w) && (h+w)){
		printf("Case %d: ",nc++);
		mat.clear();
		REP(i,h){
			cin>>s;
			mat.pb(s);
		}
		int maxdist = 0;
		REP(i,h)
			REP(j,w){
				if(mat[i][j]=='A'){
					memset(vis,0,sizeof(vis));
					tmp = -INF;
					dfs(i,j,1);
					maxdist = max(maxdist,tmp);
				}
			}
		printf("%d\n",maxdist);
	}
	return 0;
}


