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
#include <list>
#include <stack>
#include <bitset>
#include <functional>
#include <utility>
#include <sstream>
#include <cctype>
#include <ctime>

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


typedef vector<int> VI;
typedef pair<int, int> II;
typedef vector<II> VII;

vector<VI> AdjList;
VI topoSort;
int dfs_num[100];
int m[100][100]; 
int V;

void dfs2(int u){
	dfs_num[u] = 1;
	for(int j=0; j<V; j++){
		if(m[u][j]==1)
			if(dfs_num[j] == -1)
				dfs2(j);
	}
	topoSort.push_back(u);
}

int main(){
	int dp[100], prev[100];
	int last, sz, s, u, v, ncase, max;
	ncase = 0;
	while(scanf("%d",&V) && V){
		scanf("%d",&s);
		for(int i=0; i<V; i++)
			for(int j=0; j<V; j++){
				m[i][j] = 0;
			}
		topoSort.clear();
		memset(dfs_num,-1,sizeof(dfs_num));
		while(1){
			scanf("%d%d",&u,&v);
			if(u+v==0) break;
			m[u-1][v-1] = 1;
		}
		dfs2(s-1);
		reverse(topoSort.begin(), topoSort.end());
		//DP
		sz = topoSort.size();
		for(int i=0; i<sz; i++)
			dp[i] = 0;
		for(int i=0; i<sz; i++){
			for(int j=i+1; j<sz; j++){
				if(m[topoSort[i]][topoSort[j]]){
					if(dp[i]+1>dp[j]){
						dp[j] = dp[i]+1;
					}
				}
			}
		}
		last = 100;
		max = -1;
		for(int i=0; i<sz; i++)
			if(dp[i]>max){
				max = dp[i];
				last = topoSort[i];
			}else if(dp[i]==max && topoSort[i]<last){
				max = dp[i];
				last = topoSort[i];
			}		
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n",++ncase,s,max,last+1);
		printf("\n");
	}
	return 0;
}
