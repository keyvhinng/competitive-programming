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
#include <list>
#include <stack>
#include <bitset>
#include <functional>
#include <utility>
#include <sstream>
#include <cctype>
#include <ctime>

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

#define MAX 1001

typedef long long ll;
typedef pair<int,int> pii;

int AdjMat[MAX][MAX];
vector<int> topoSort;
int dfs_num[MAX];
int N;
int cycle;

void dfs2(int u){
	int v;
	dfs_num[u] = 0;
	for(int j=1; j<=N; j++){
		if(AdjMat[u][j]==1){
			if(dfs_num[j]==0){
				cycle = 1;
				break;
			}
			else if(dfs_num[j]==-1){
				dfs2(j);
			}
		}
	}
	dfs_num[u] = 1;
	topoSort.push_back(u);
}

int main(){
	int m, u, v, uniq;
	while(scanf("%d %d",&N, &m) && (N+m)){
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				AdjMat[i][j] = 0;
			}
			dfs_num[i] = -1;
		}
		for(int i=0; i<m; i++){
			scanf("%d %d",&u, &v);
			AdjMat[u][v] = 1;
		}	
		topoSort.clear();
		cycle = 0;
		for(int i=1; i<=N; i++){
			if(dfs_num[i]==-1){
				dfs2(i);
				if(cycle)
					break;
			}
		}
		if(cycle){
			printf("0\n");	
		}else{
			reverse(topoSort.begin(), topoSort.end());
			//check
			uniq = 1;
			for(int i=0; i<topoSort.size()-1; i++){
				if(AdjMat[topoSort[i]][topoSort[i+1]]==0){
					uniq = 0;
				}
			}
			if(uniq)
				printf("1\n");
			else
				printf("2\n");
		}
	}
	return 0;
}
