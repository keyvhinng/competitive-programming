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
#include <iomanip>
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
#define sz size

#define f(i,x,y) for(int i=x; i<y; i++)

using namespace std;

typedef vector<int> VI;
typedef pair<int,int> II;

int V, E, cl, dfsRoot, cont, rootChildren;
//vector<VI> adjList;
int g[200][200], br[200][200];
VI dfs_num, dfs_low, dfs_parent;
vector<II> vp;

void dfs(int u){
	int v;
	dfs_num[u] = dfs_low[u] = cont++;
	f(j,0,V){
		if(g[u][j]){
			v = j;
			if(dfs_num[v]==-1){
				dfs_parent[v] = u;
				dfs(v);
				if(dfs_low[v]>dfs_num[u]){
					br[u][v] = br[v][u] = 1;
					cl++;
				}
				dfs_low[u] = min(dfs_low[u],dfs_low[v]);
			}else if(dfs_parent[u]!=v){
				dfs_low[u] = min(dfs_low[u],dfs_num[v]);
			}
		}
	}
}

int toInt(string s){
	int ans;
	ans = 0;
	f(i,1,(int)s.size()-1){
		ans *= 10;
		ans += s[i]-'0';
	}
	return ans;
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int v, u, k, flag;
	string s;
	while(scanf("%d",&V)==1){
		memset(g,0,sizeof(g));
		memset(br,0,sizeof(g));
		dfs_num.assign(V,-1);
		dfs_low.assign(V,0);
		dfs_parent.assign(V,0);
		f(i,0,V){
			scanf("%d",&u);	
			cin>>s;
			k = toInt(s);
			f(j,0,k){
				scanf("%d",&v);
				g[u][v] = g[v][u] = 1;
				//adjList[u].push_back(v);
				//printf(" [%d %d]\n",u,v);
			}
		}
		cont = 0;
		vp.clear();
		cl = 0;
		f(i,0,V)
			if(dfs_num[i]==-1)
				dfs(i);
		printf("%d critical links\n",cl);
		sort(vp.begin(),vp.end());
		f(i,0,V)
			f(j,0,V)
				if(br[i][j]){
					printf("%d - %d\n",i,j);
					br[j][i] = 0;
				}
		printf("\n");
	}

	return 0;
}

