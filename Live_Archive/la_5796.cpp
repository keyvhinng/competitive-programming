#include <algorithm>
#include <bitset>
#include <deque>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
#define clr(a, v) memset(a, v, sizeof(a))
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define REPN(i,s,n) for(int i=s;i<(int)(n);i++)
#define REP(i,n) REPN(i,0,n)
#define REPIT(i,x) for( typeof x.begin()  i=x.begin(); i!=x.end(); i++ )
#define trace(x)    cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;

using namespace std;

typedef long long int64;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <string> vs;
typedef vector <ii> vii;
#define MAXN 10000
const int INF = 2e9+9;

vector< pair<int,int> > edges;
vector<int> adj[MAXN];
vector<int> adj2[MAXN];
int vis[MAXN];
int dfs_low[MAXN];
int dfs_num[MAXN];
int parent[MAXN];

int n, m, cont, root;

class UnionFind{
	private:
		vi p, rank, setSize;
		int numSets;
	public:
		UnionFind(int n){
			setSize.assign(n,1); numSets=1; rank.assign(n,0);
			p.assign(n,0); for(int i=0; i<n; i++) p[i]=i;
		}

		int findSet(int i){ return (p[i]==i)? i : (p[i]=findSet(p[i])); }
		
		bool isSameSet(int i, int j){ return findSet(i)==findSet(j); }

		void unionSet(int i, int j){
			if(!isSameSet(i,j)){
				numSets--;
				int x = findSet(i);
				int y = findSet(j);
				if(rank[x]>rank[y]){ 
					p[y]=x; setSize[x] += setSize[y];
				}
				else {
					p[x]=y; setSize[y] += setSize[x];
					if(rank[x]==rank[y]) rank[y]++;
				}
			}
		}

		int numDisjointSets() { return numSets; }
		int sizeOfSet(int i)  { return setSize[findSet(i)]; }
};

void dfs(int u){
	int v;
	dfs_num[u] = dfs_low[u] = cont++;
	for(int j=0; j<(int)adj[u].size(); j++){
		v = adj[u][j];
		if(dfs_num[v]==-1){
			parent[v] = u;
			dfs(v);
			if(dfs_num[u]<dfs_low[v]){
				edges.pb(mp(u,v));
			}
			dfs_low[u] = min(dfs_low[u],dfs_low[v]);
		}else if(parent[u]!=v)
			dfs_low[u] = min(dfs_low[u],dfs_num[v]);
	}
}

int main(){
	int u, v, q;
	while(scanf("%d%d%d",&n,&m,&q) && (n+m)){
		cont = 0;
		edges.clear();
		REP(i,n) adj[i].clear();
		REP(i,m){
			scanf("%d%d",&u,&v);
			u--; v--;
			adj[u].pb(v);
			adj[v].pb(u);
		}

		memset(dfs_num,-1,sizeof(dfs_num));
		REP(i,n) if(dfs_num[i]==-1) dfs(i); 

		UnionFind uf(n);
		REP(i,edges.size()){
			uf.unionSet(edges[i].first,edges[i].second);
		}	

		REP(i,q){
			scanf("%d%d",&u,&v);
			u--; v--;
			if(uf.isSameSet(u,v)) printf("Y\n");
			else printf("N\n");
		}
		printf("-\n");
	}
	return 0;
}


