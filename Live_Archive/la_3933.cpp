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

int R, C;

char m[110][110];

int dx[6] = {-1,-1, 0, 0, 1, 1};
int dy[6] = { 0, 1,-1, 1,-1, 0};
char color[2] = {'(',')'};


bool valid(int x, int  l){
	if(x>=0 && x<l) return true;
	return false;
}

void dfs_2(int x, int y){
	m[x][y] = 'B';
	int nx, ny;
	for(int i=0; i<6; i++){
		nx = x + dx[i];
		ny = y + dy[i];
		if(valid(nx,R) && valid(ny,C)){
			if(m[nx][ny]!='B' && m[nx][ny]!='.') dfs_2(nx,ny);
		}
	}
}

int dfs(int x, int y, int s){
	int nx, ny, r;
	m[x][y] = color[s];
	for(int i=0; i<6; i++){
		nx = x + dx[i];
		ny = y + dy[i];
		r = 1;
		if(valid(nx,R) && valid(ny,C)){
			if(m[nx][ny]=='*'){
				r = dfs(nx,ny,1-s);
				if(r==-1) break;
			}else if(m[nx][ny]==color[s]){
				r = -1;
				break;
			}
		}
	}
	if(r==-1){
		m[x][y]='B';
	}
	return r;
}

int main(){
	char c;
	while(scanf("%d%d",&R,&C) && (R+C)){
		scanf("%c",&c);

		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++) scanf("%c",&m[i][j]);
			scanf("%c",&c);
		}

		for(int i=0; i<R; i++)
			for(int j=0; j<C; j++) if(m[i][j]=='I') dfs(i,j,0);
		
		/*
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++) printf("%c",m[i][j]);
			printf("\n");
		}
		printf("\n");
		*/

		for(int i=0; i<R; i++)
			for(int j=0; j<C; j++) if(m[i][j]=='B') dfs_2(i,j);

		for(int i=0; i<R; i++)
			for(int j=0; j<C; j++) if(m[i][j]=='*') m[i][j] = 'F';

		printf("\n");
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++) printf("%c",m[i][j]);
			printf("\n");
		}
	}
	return 0;
}


