#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
#define MAXN 110
const int INF=2e9+9;
int n, m, k;
int adj[MAXN][MAXN];
int dist[MAXN];
int vis[MAXN];


int dfs2(int u){
	vis[u] = 1;
	if(u==k) return 1;
	for(int v=0; v<n; v++){
		if(adj[u][v] && vis[v]==-1)
			if(dfs2(v)) return 1;
	}
	return 0;
}

void bfs(int s){
	int u;
	for(int i=0; i<n; i++) dist[i] = INF;
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		u = q.front(); q.pop();
		for(int v=0; v<n; v++){
			if(adj[v][u] && dist[u]+1<dist[v]){
				q.push(v);
				dist[v] = dist[u]+1;
			}
		}
	}
}

int main(){
	int ncases, u, v;
	string s;
	scanf("%d",&ncases);
	for(int nc=0; nc<ncases; nc++){
		memset(adj,0,sizeof(adj));
		scanf("%d%d\n",&n,&k);
		getline(cin,s);
		while((int)s.size()){
			stringstream ss(s);
			ss>>u;
			ss>>v;
			adj[u][v] = 1;
			getline(cin,s);
		}
		bfs(k);
		int ans, ansd;
		ansd = dist[0];
		//ans = 0;
		for(int i=0; i<n; i++){
			if(i==k) continue;
			memset(vis,-1,sizeof(vis));
			vis[i] = 1;
			if(!dfs2(0) && dist[i] <  ansd){
				ans = i;
				ansd = dist[i];
			}
		}
		if(nc) printf("\n");
		printf("Put guards in room %d.\n",ans);
	}
	return 0;	
}
