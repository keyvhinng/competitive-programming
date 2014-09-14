
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

#define MAX 1000010
#define DFS_BLACK 1
#define DFS_WHITE -1
#define DFS_GREY 0

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<long> vl;
typedef vector<ii> vii;

vl topoSort;
long dfs_num[MAX];
vector<long> AdjList[MAX];
int cycle;

void dfs2(long u){
	long v;
	dfs_num[u] = DFS_GREY;
	for(int j=0; j<(int)AdjList[u].size(); j++){
		v = AdjList[u][j];
		if(dfs_num[v] == DFS_WHITE){
			dfs2(v);
		}else if(dfs_num[v] == DFS_GREY){
			cycle = 1;
		}
	}
	dfs_num[u] = DFS_BLACK;
	topoSort.pb(u);
}

int main(){
	int n, m;
	long int a, b;
	while(scanf("%d %d",&n, &m) && (n+m!=0)){
		cycle = 0;
		topoSort.clear();
		memset(dfs_num, DFS_WHITE, sizeof dfs_num);
		f(i,0,n){
			AdjList[i].clear();
		}
		f(i,0,m){
			scanf("%ld %ld",&a, &b);
			AdjList[a-1].pb(b-1);
		}	
		for(int i=0; i<n; i++){
			if(dfs_num[i] == DFS_WHITE){
				dfs2(i);
			}
		}
		if(cycle){
			printf("IMPOSSIBLE\n");
		}else{
			reverse(topoSort.begin(), topoSort.end());
			for(int i=0; i<(int)topoSort.size(); i++){
				printf("%ld\n",topoSort[i]+1);
			}
		}
	}
	return 0;
}
