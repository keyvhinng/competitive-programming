//LA 2817
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

#define DFS_WHITE -1
#define DFS_BLACK 1

typedef long long ll;
typedef pair<int,int> pii;

vector<int> AdjList[30010];


int dfs_num[30010];
int cont;


void dfs(int u){
	//cout<<"adding "<<u<<endl;
	int  v;
	dfs_num[u] = DFS_BLACK;
	for(int j=0; j<AdjList[u].size(); j++){
		v = AdjList[u][j];
		if(dfs_num[v]==DFS_WHITE){
			dfs(v);
		}
	}
	cont++;
}



int main(){
	int m, n, k, v;
	int arr[30010];
	while(scanf("%d %d",&n, &m)&& (m+n!=0)){
		for(int i=0; i<n; i++){
			AdjList[i].clear();
		}
		cont = 0;
		memset(dfs_num,DFS_WHITE,sizeof dfs_num);
		for(int i=0; i<m; i++){
			scanf("%d",&k);
			for(int j=0; j<k; j++){
				scanf("%d",&arr[j]);
			}
			for(int p=0; p<k; p++){
				for(int q=0; q<k; q++){
					if(p!=q){
					//	printf("add %d %d\n",arr[p], arr[q]);
						AdjList[arr[p]].pb(arr[q]);
					}
				} 
			}
		}
		dfs(0);
		printf("%d\n",cont);
	}
	return 0;
}
