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

#define dfs_WHITE -1
#define dfs_BLACK 1
#define dfs_GRAY 2

using namespace std;

typedef vector<int> VI;

int V, E, chief;
int dp[50000], dfs_num[50000];
int adjList[50000], vcont[50000];

pair<int,int> dfs(int u, int cont){
	pair<int, int> ans, r;
	int v;
	ans.first = 1;
	vcont[u] = cont;
	dfs_num[u] = dfs_GRAY;

	v = adjList[u];
	if(dfs_num[v]==dfs_WHITE){
		r = dfs(v,cont+1);
		ans.second = r.second - 1;
		if(r.second>0){
			ans.first  = r.first;
		}else{
			ans.first  = r.first + 1;
		}
	}else if(dfs_num[v]==dfs_GRAY){
		ans.first = vcont[u]-vcont[v];
		ans.second = vcont[u]-vcont[v];
	}else{
		ans.first = dp[v] + 1;
	}

	dfs_num[u] = dfs_BLACK;
	dp[u] = ans.first;
	return ans;
}

int main(){
	int ncases, u, v, ans;
	pair<int, int> curr;
	scanf("%d",&ncases);
	for(int k=1; k<=ncases; k++){
		printf("Case %d: ",k);
		scanf("%d",&V);
		clr(dfs_num,-1);
		f(i,0,V){
			scanf("%d%d",&u,&v);
			u--; v--;
			adjList[u] = v;
		}
		ans = 0;
		f(i,0,V){
			if(dfs_num[i]==dfs_WHITE){
				curr = dfs(i,1);
				if(ans<curr.first){
					ans = curr.first;
					chief = i;
				}
			}
		}
		printf("%d\n",chief+1);
	}
	return 0;
}

