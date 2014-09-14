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

using namespace std;

int adjMatrix[100][100];
int m[100][100];
int reach[100], dom[100];
int V, v;


void dfs(int u){
	reach[u] = 1;
	f(i,0,V){
		if(m[u][i]==1 && reach[i]==0){
			dfs(i);
		}
	}
	return;
}

void dfs2(int u){
	if(u==v) return;
	dom[u] = 0;
	f(i,0,V){
		if(m[u][i]==1 && dom[i]==1){
			dfs2(i);
		}
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int ncases;
	scanf("%d",&ncases);
	for(int k=1; k<=ncases; k++){
		printf("Case %d:\n",k);
		scanf("%d",&V);
		f(i,0,V){
			f(j,0,V){
			   	scanf("%d",&m[i][j]);
			}
		}
		memset(reach,0,sizeof(reach));
		dfs(0);
		printf("+");
		f(i,0,2*V-1) printf("-");
		printf("+\n");
		f(i,0,V){
			v = i;	
			f(j,0,V) dom[j] = reach[j];
			dfs2(0);
			f(j,0,V){
				printf("|");
				if(dom[j]) printf("Y");
				else printf("N");
			}
			printf("|\n");
			printf("+");
			f(j,0,2*V-1) printf("-");
			printf("+\n");
		}
	}
	return 0;
}

