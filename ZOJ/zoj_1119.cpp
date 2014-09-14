#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 1010
int counter, root, numchild, down;
int dfs_num[MAXN], dfs_low[MAXN], parent[MAXN];
int cut_vertex[MAXN], exist[MAXN];
vector<int> adj[MAXN];

void bridges(int u){
	dfs_num[u] = dfs_low[u] = counter++;
	int v;
	for(int j=0; j<(int)adj[u].size(); j++){
		v = adj[u][j];
		if(dfs_num[v]==-1){
			if(u==root) numchild++;
			parent[v] = u;
			bridges(v);
			//cut vertex
			if(dfs_num[u]<=dfs_low[v]){
				cut_vertex[u] = 1;
			}
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
		}else if(v!=parent[u]){
			dfs_low[u] = min(dfs_low[u],dfs_num[v]);
		}
	}
}

void dfs(int u){
	dfs_num[u]=1;
	int v;
	for(int j=0; j<(int)adj[u].size(); j++){
		v = adj[u][j];
		if(v!=down && dfs_num[v]==-1) dfs(v);
	}
}

int main(){
	int u, v, nc;
	nc = 1;
	scanf("%d",&u);
	while(u!=0){
		memset(exist,0,sizeof(exist));
		printf("Network #%d\n",nc++);
		for(int i=0; i<MAXN; i++) adj[i].clear();
		scanf("%d",&v);
		u--; v--;
		exist[u] = exist[v] = 1;
		adj[u].push_back(v);
		adj[v].push_back(u);
		scanf("%d",&u);
		while(u!=0){
			scanf("%d",&v);
			u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
			exist[u] = exist[v] = 1;
			scanf("%d",&u);
		}
		memset(cut_vertex,0,sizeof(cut_vertex));
		memset(dfs_num,-1,sizeof(dfs_num));
		counter = 0;
		for(int i=0; i<MAXN; i++) if(dfs_num[i]==-1){
			numchild = 0;
			root = i;
			bridges(i);
			cut_vertex[i] = numchild > 1;
		}
		int found = 0;
		for(int i=0; i<MAXN; i++) if(cut_vertex[i]){
			found=1; break;
		}
		if(!found){
			printf("  No SPF nodes\n");
		}else{
			for(int i=0; i<MAXN; i++){
				if(cut_vertex[i]){
					printf("  SPF node %d leaves ",i+1);
					down = i;
					memset(dfs_num,-1,sizeof(dfs_num));
					int ncomp = 0; 
					for(int j=0; j<MAXN; j++){
						if(exist[j] && dfs_num[j]==-1 && j!=down){ ncomp++;  dfs(j); }
					}
					printf("%d subnets\n",ncomp);
				}
			}
		}
		scanf("%d",&u);
		if(u) printf("\n");
	}
	return 0;
}
