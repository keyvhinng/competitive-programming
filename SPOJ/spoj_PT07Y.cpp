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

#define BLACK -1
#define GRAY 0
#define WHITE 1

typedef long long ll;
typedef pair<int,int> pii;

int dfs_num[10010];
vector<int> AdjList[10010];
int flag;

void DFS(int u, int p){
	int v;
	dfs_num[u] = GRAY;
	for(int i=0; i<AdjList[u].size(); i++){
		v = AdjList[u][i];
		if(v!=p){
			if(dfs_num[v]==GRAY){
				flag = 1;
				break;
			}else if(dfs_num[v]==WHITE){
				DFS(v,u);
			}
		}
	}
	dfs_num[u] = BLACK;
}

int main(){
	int N, M, u, v, r;
	scanf("%d %d",&N, &M);
	f(i,0,N){
		AdjList[i].clear();	
		dfs_num[i] = WHITE;
	}
	f(i,0,M){
		scanf("%d %d",&u, &v);
		AdjList[u-1].pb(v-1);
		AdjList[v-1].pb(u-1);
	}
	r = 0;
	while(r<N && AdjList[r].size()==0){
		r++;
	}
	flag = 0;
	DFS(r,r);
	if(flag){
		//check cycle
		printf("NO");
	}else{
		//check connectivity 
		r++;
		while(r<N && (dfs_num[r]==BLACK || AdjList[r].size()==0)){
			r++;
		}
		if(r<N){
			printf("NO");
		}else{
			printf("YES");
		}
	}
	return 0;
}
