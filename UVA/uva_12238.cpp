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

#define MAXN 100010

typedef long long int64;
typedef vector <int> vi;
typedef pair <int,int64> ii;
typedef vector <string> vs;
typedef vector <ii> vii;

const int INF = 2e9+9;

int n;
vii adj[MAXN];
int64 dist[MAXN];

//rmq
vi a, Log2;
vector<vi> p;

int pairmin(int i1, int i2){
	return a[i1]<a[i2]?i1:i2;
}

void init(vi &_a){
	a = _a;
	int n = a.size();
	Log2.resize(n+1);
	for(int i=1,k=0; i<=n; i++){
		Log2[i] = k;
		if(1<<(k+1) == i) k++;
	}

	int ln=Log2[n];
	p.assign(ln+1,vector<int>(n));
	for(int i=0; i<n; i++) p[0][i]=i;
	for(int i=1; i<=ln; i++)
		for(int j=0; j+(1<<i)-1<n; j++){
			int i1 = p[i-1][j];
			int i2 = p[i-1][j + (1 << (i-1))];
			p[i][j] = pairmin(i1,i2);
		}
}

int query(int b, int e){
	int ln = Log2[e-b+1];
	int i1 = p[ln][b];
	int i2 = p[ln][e - (1<<ln)+1];
	return pairmin(i1,i2);
}

//lca
vi L;
int nE, E[2*MAXN], R[MAXN], vis[MAXN];

void euler(int u, int p, int el){
	int v;
	E[nE++] = u; L.pb(el);
	vis[u] = 1;
	REP(j,adj[u].size()){
		v = adj[u][j].first;
		if(!vis[v] && v!=p){
			euler(v,u,el+1);
			E[nE++] = u; L.pb(el);
		}
	}
}

void preprocess(int root){
	nE = 0;
	L.clear();
	memset(vis,0,sizeof(vis));
	euler(root,-1,0);
	for(int i=2*n-2; i>=0; i--) R[E[i]] = i;
	init(L);
}


int lca(int u, int v){
	return E[query(min(R[u],R[v]),max(R[u],R[v]))]; 
}

void dfs(int u){
	REP(j,adj[u].size()){
		int v = adj[u][j].first;
		if(dist[v]==-1){
			dist[v] = dist[u] + adj[u][j].second;
			dfs(v);
		}
	}
	return;
}

int main(){
	int64 ans, w;
	int a, l, q, u, v;
	while(scanf("%d",&n) && n){
		REP(i,n+1){
			dist[i] = -1;
			adj[i].clear();
		}
		for(int i=1; i<n; i++){
			scanf("%d %lld",&a,&w);
			adj[i].pb(mp(a,w));;
			adj[a].pb(mp(i,w));
		}
		dist[0] = 0;
		dfs(0);
		scanf("%d",&q);
		preprocess(0);
		REP(i,q){
			scanf("%d%d",&u,&v);
			ans = dist[u] + dist[v] - 2*dist[lca(u,v)];
			if(i) printf(" ");
			printf("%lld",ans);
		}
		printf("\n");
	}
	return 0;
}

