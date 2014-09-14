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

#define DFS_WHITE -1
#define DFS_BLACK 1
#define DFS_GRAY 2

using namespace std;

typedef vector<int> VI;

vector<VI> adjList;
VI dfs_num;
VI dfs_parent;
VI topoSort;
int V, E, hasCycle;

bool adj(int u, int v){
	bool ans = false;
	for(int j=0; j<adjList[u].size(); j++){
		if(adjList[u][j]==v){
			ans = true;
			break;
		}
	}
	return ans;
}

void dfs2(int u){
	dfs_num[u] = DFS_BLACK;
	for(int j=0; j<adjList[u].size(); j++){
		 int v = adjList[u][j];
		 if(dfs_num[v]==DFS_WHITE){
		 	dfs2(v);
		 }
	}
	topoSort.pb(u);
}

void graphCheck(int u){
	dfs_num[u] = DFS_GRAY;
	for(int j=0; j<(int)adjList[u].size(); j++){
		int v = adjList[u][j];
		if(dfs_num[v]==DFS_WHITE) 
			graphCheck(v);	
		else if(dfs_num[v]==DFS_GRAY){
			hasCycle = 1;
			break;
		}
	}	
	dfs_num[u] = DFS_BLACK;
}

int main(){
	int ncases, u, v, ok;
	scanf("%d",&ncases);
	while(ncases--){
		topoSort.clear();
		hasCycle = 0;
		scanf("%d%d",&V,&E);
		adjList.assign(V,VI());
		dfs_num.assign(V,DFS_WHITE);
		f(i,0,E){
			scanf("%d%d",&u,&v);
			u--;
			v--;
			adjList[u].pb(v);
		}
		f(i,0,V){
		   	if(dfs_num[i]==DFS_WHITE) graphCheck(i);
			if(hasCycle) break;
		}
		if(hasCycle){
		   	printf("recheck hints\n");
		   	continue;
		}
		dfs_num.assign(V,DFS_WHITE);
		f(i,0,V){
			if(dfs_num[i]==DFS_WHITE) dfs2(i);
		}
		reverse(topoSort.begin(), topoSort.end());
		ok = 1;
		f(i,1,topoSort.size()){
			if(!adj(topoSort[i-1],topoSort[i])){
				ok = 0;
				break;
			}
		}
		if(ok){
			f(i,0,topoSort.size()){
				if(i) printf(" ");
				printf("%d",topoSort[i]+1);
			}
		}else{
			printf("missing hints");
		}
		printf("\n");
	}
	return 0;
}

