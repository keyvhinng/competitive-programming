#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#define fo(i,x,y) for(int i=x; i<y; i++)
#define INF 10000000
using namespace std;

int n, s, t, f;
int g[100][100], p[100], vis[100];
int res[100][100];

void augment(int u, int minEdge){
	if(u==s){
		f = minEdge;
		return ;
	}
	else if(p[u]!=-1){
		augment(p[u], min(minEdge,res[p[u]][u]));
		res[p[u]][u] -= f;
		res[u][p[u]] += f;
	}
}

int maxflow(void){
	int u, ans;
	ans = 0;
	fo(i,0,n)
		fo(j,0,n)
			res[i][j] = g[i][j];
	while(1){
		memset(vis,0,sizeof(vis));
		queue<int> q;
		fo(i,0,n) p[i]=-1;
		q.push(s);
		while(!q.empty()){
			u = q.front(); q.pop();
			if(u==t) break;
			fo(i,0,n){
				if(res[u][i]>0 && vis[i]==0){
					vis[i]=1;
					q.push(i);
					p[i] = u;
				}
			}
		}
		f=0;
		augment(t,INF);
		if(f==0) break;
		ans += f;
	}
	return ans;
}

int main(){
	int c, u, v, w, nc;
	nc = 0;
	while(scanf("%d",&n) && n){
		fo(i,0,n)
			fo(j,0,n)
				g[i][j]=0;
		scanf("%d%d%d",&s,&t,&c);
		s--; t--;
		fo(i,0,c){
			scanf("%d%d%d",&u,&v,&w);
			u--; v--;
			g[u][v] += w;
			g[v][u] += w;
		} 
		printf("Network %d\n",++nc);
		printf("The bandwidth is %d.\n",maxflow());
		printf("\n");
	}
	return 0;
}
