//UVA 558
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

#define MAXN 1010
#define MAXM 4050
#define INF 0x3f3f3f3f

int orig[MAXM], dest[MAXM], peso[MAXM];

int d[MAXN], pai[MAXN];

int bellman_ford(int s, int n, int m){
	int i, j;
	memset(pai, -1, sizeof(pai));
	pai[s] = s;
	for(i=0; i<n; i++){
		d[i] = INF;
	}
	d[s] = 0;
	for(i=0; i<n-1; i++){
		for(j=0; j<m; j++){
			int u = orig[j], v = dest[j], w = peso[j];
			if(d[u] != INF && d[v] > d[u]+w){
				d[v] = d[u] + w;
				pai[v] = u;
			}
		}
	}
	for (j=0; j<m; j++){
		int u= orig[j], v = dest[j], w= peso[j];
		if(d[u] != INF && d[v] > d[u]+w) return 0;
	}
	return 1;

}

int main(){
	int n, m, ncases;
	int from, to, cost;
	int origem, destino;
	scanf("%d",&ncases);
	while(ncases--){
		scanf("%d %d", &n, &m);
		int k = 0;
		f(i,0,m){
			scanf("%d %d %d",&from, &to, &cost);
			orig[k] = from;
			dest[k] = to;
			peso[k] = cost;
			k++;
		}
		origem = 0;
		destino = n-1;
		if(bellman_ford(origem,n,m)==0){
			printf("possible\n");
		}else{
			printf("not possible\n");
		}
	}
	return 0;
}
