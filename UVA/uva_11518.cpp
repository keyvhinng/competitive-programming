//UVA 11518
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

int dfs_num[10001];
vector<int> AdjList[10001];
int cont;

void dfs(int u){
	//cout<<"visited "<<u<<endl;
	cont++;
	int v;
	dfs_num[u] = DFS_BLACK;
	for(int j=0; j<AdjList[u].size(); j++){
		v = AdjList[u][j];
		if(dfs_num[v] == DFS_WHITE){
			dfs(v);
		}
	}
}

int main(){
	int ini, ncases, n, m, l, u, v;
	scanf("%d",&ncases);
	while(ncases--){
		scanf("%d %d %d",&n, &m, &l);
		cont = 0;
		//clear
		for(int i=0; i<n; i++){
			AdjList[i].clear();
		}
		memset(dfs_num, -1, sizeof dfs_num);
		for(int i=0; i<m; i++){
			scanf("%d %d",&u, &v);
			AdjList[u-1].pb(v-1);
		}
		for(int i=0; i<l; i++){
			scanf("%d",&ini);
			if(dfs_num[ini-1]==DFS_WHITE)
				dfs(ini-1);
		}
		printf("%d\n",cont);
	}
	return 0;
}
