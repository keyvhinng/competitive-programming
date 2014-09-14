#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <bitset>

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> II;
typedef vector<II> VII;

vector<VII> AdjList;
VI dfs_num;
int end;
int maxlen;

int dfs(int u, int d){
	int v;
	if(d > maxlen){
		maxlen = d;
		end = u;
	}
	dfs_num[u] = 1;
	for(int j=0; j<AdjList[u].size(); j++){
		II v = AdjList[u][j];
		if(dfs_num[v.first]==-1)
			dfs(v.first,d+v.second);
	}
	
}

int main(){
	int ncases;
	int u, v, w, V, E;
	scanf("%d",&ncases);
	while(ncases--){
		scanf("%d",&V);
		AdjList.assign(V, VII());
		
		for(int i=1; i<V; i++){
			scanf("%d %d %d",&u, &v, &w);
			AdjList[u-1].push_back(make_pair(v-1,w));
			AdjList[v-1].push_back(make_pair(u-1,w));	
		}
		dfs_num.assign(V, -1);
		maxlen = -1;
		dfs(0,0);
		dfs_num.assign(V, -1);
		maxlen = -1;
		//printf("end %d\n",end);
		dfs(end,0);
		printf("%d\n",maxlen);
	}
  	return 0;
}

