//UVA 10305
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

#define DFS_WHITE -1
#define DFS_BLACK 1

typedef long long ll;
typedef pair<int,int> pii;

int dfs_num[110];
vector<int> topoSort;
vector<int> AdjList[110];

void dfs2(int u){
	int v;
	dfs_num[u] = DFS_BLACK;
	for(int j=0; j<(int)AdjList[u].size(); j++){
		v = AdjList[u][j];
		if(dfs_num[v]==DFS_WHITE){
			dfs2(v);
		}
	}
	topoSort.pb(u);
}

int main(){
	int m, n, u, v;
	while(scanf("%d %d",&n, &m) &&(m+n!=0)){
		//clear
		topoSort.clear();
		memset(dfs_num,DFS_WHITE,sizeof dfs_num);
		for(int i=0; i<m; i++){
			scanf("%d %d", &v, &u);
			//printf("%d %d\n",v, u);
			AdjList[v-1].pb(u-1);
		}
		//run
		for(int i=0; i<n; i++){
			if(dfs_num[i]==DFS_WHITE){
				dfs2(i);
			}	
		}
		reverse(topoSort.begin(), topoSort.end());
		for(int i=0; i<(int)topoSort.size(); i++){
			if(i)
				printf(" ");
			printf("%d",topoSort[i]+1);
		}
		printf("\n");

	}
	return 0;
}
