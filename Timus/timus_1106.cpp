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

const int INF = 2e9+9;

vector<vi> adj;
int vis[110];

int main(){
	int n, u, v;
	scanf("%d",&n);
	adj.assign(n,vi());
	for(int i=0; i<n; i++){
		vis[i]=-1;
		scanf("%d",&v);
		while(v!=0){
			v--;
			adj[i].pb(v);
			scanf("%d",&v);
		}
	}

	for(int i=0; i<n; i++){
		if(vis[i]==-1){
			queue<int> q;
			q.push(i);
			vis[i] = 1;
			while(!q.empty()){
				u = q.front();
				q.pop();
				for(int j=0; j<(int)adj[u].size(); j++){
					v = adj[u][j];
					if(vis[v]==-1){
						vis[v] = vis[u] + 1;
						q.push(v);
					}
				}
			}
		}
	}
	
	vector<int> ans;
	for(int i=0; i<n; i++){
		if(vis[i]>0 && vis[i]%2==0){
			ans.pb(i+1);
		}
	}

	printf("%d\n",(int)ans.size());
	for(int i=0; i<(int)ans.size(); i++){
		if(i) printf(" ");
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}


