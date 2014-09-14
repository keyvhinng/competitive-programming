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

#define MAX 0xfffffff
#define MIN -1 

typedef long long ll;
typedef pair<int,int> pii;

vector<int> AdjList[5010];
int dfs_num[5010];
int HD[5010][2];
int HU[5010];

void dfs(int u){
	int v;
	dfs_num[u] = 1;
	for(int i=0; i<AdjList[u].size(); i++){
		v = AdjList[u][i];
		if(dfs_num[v]==-1){
			dfs(v);
			if(HD[v][0]+1 > HD[u][1]){
				HD[u][1] = HD[v][0]+1;
			}
			if(HD[u][1] > HD[u][0]){
				swap(HD[u][0], HD[u][1]);
			}
		}
	}
}

void dfs2(int u, int l){
	int v, hu;
	HU[u] = l;
	dfs_num[u] = 1;
	for(int i=0; i<AdjList[u].size(); i++){
		v =  AdjList[u][i];
		if(dfs_num[v]==-1){
			if(HD[v][0]+1 != HD[u][0]){
				hu = HD[u][0];
			}else{
				hu = HD[u][1];
			}
			hu = max(hu,HU[u]);
			dfs2(v,hu+1);
		}
	}
}


int main(){
	int N, k, z, best, worst;
	int root[5010];
	while(scanf("%d",&N)==1){
		for(int i=1; i<=N; i++){
			AdjList[i].clear();
			dfs_num[i] = -1;
			scanf("%d",&k);
			while(k--){
				scanf("%d",&z);
				AdjList[i].pb(z);
			}
			HD[i][0] = 0;
			HD[i][1] = 0;
			HU[i]   = 0;
			dfs_num[i] = -1;
		}
		//dfs_num[1] = 1;
		dfs(1);
		for(int i=1; i<=N; i++)
			dfs_num[i] = -1;
		dfs_num[1] = 1;
		dfs2(1,0);
		best  = MAX;
		worst = MIN;
		for(int i=1; i<=N; i++){
			root[i] = max(HD[i][0],HU[i]);
			best  = min(root[i], best);
			worst = max(root[i],worst);
		}
		printf("Best Roots  :");
		for(int i=1; i<=N; i++){
			if(root[i] == best){
				printf(" %d",i);	
			}
		}
		printf("\nWorst Roots :");
		for(int i=1; i<=N; i++){
			if(root[i]==worst){
				printf(" %d",i);
			}
		}
		printf("\n");
	}
	return 0;
}
