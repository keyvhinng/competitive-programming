#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define pb push_back
#define MAX 10010
using namespace std;
typedef vector<int> vi;
vector<vi> adjList;
vector<vi> nadjList;
int n, m, counter;
int vis[MAX], dfs_num[MAX], dfs_low[MAX], p[MAX];
int cv[MAX], out[MAX], cont;
bool exist[MAX];

void dfs(int u){
	int j;
	vis[u]=1;
	dfs_num[u] = dfs_low[u] = counter++;
	for(j=0; j<(int)adjList[u].size(); j++){
		int v = adjList[u][j];
		if(!vis[v]){
			p[v] = u;
			dfs(v);
			if(dfs_low[v]>dfs_num[u]){
			printf("bridge %d %d\n",u+1,v+1);
				nadjList[u].pb(v);
				nadjList[v].pb(u);
				cv[u] = 1;
			}
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
		}else if(v!=p[u]){
			dfs_low[u] = min(dfs_low[u],dfs_num[v]);
		}
	}
}

void dfs2(int u){
	int v, j;
	vis[u]=1;
	cont++;
	for(j=0; j<(int)nadjList[u].size(); j++){
		v = nadjList[u][j];
		if(!vis[v]){
			dfs2(v);
		}
	}
}

int main(){
	int u, v, i ,j ,ncases, nc;
	scanf("%d",&ncases);
	for(nc=1; nc<=ncases; nc++){
		scanf("%d%d",&n,&m);
		adjList.assign(n,vi());
		nadjList.assign(n,vi());
		memset(cv,0,n*sizeof(int));
		memset(vis,0,n*sizeof(int));
		memset(out,0,n*sizeof(int));
		counter = 0;
		for(i=0; i<m; i++){
			scanf("%d%d",&u,&v);
			u--; v--;
			out[u]++; out[v]++;
			adjList[u].pb(v);
			adjList[v].pb(u);
		}

		// cut vertex and bridges
		for(i=0; i<n; i++)
			if(!vis[i] && out[i]==1) dfs(i);

		long long int ans = 0;
		memset(vis,0,n*sizeof(int));
		for(i=0; i<n; i++){
			if(!vis[i]){
				cont = 0;
				dfs2(i);
				if(cont%2){
					ans += (cont)*((cont-1)/2);
				}else
					ans += (cont/2)*(cont-1);
				//ans += (cont*(cont-1))/2;
			}
		}
		printf("Case #%d: %lld\n",nc,ans);
	} 
	return 0;
}
