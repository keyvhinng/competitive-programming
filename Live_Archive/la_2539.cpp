
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

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


vi pset;

void initSet(int N){
	pset.assign(N, 0);
	for(int i=0; i<N; i++) pset[i] = i;
}

int findSet(int i){
	return (pset[i]==i) ? i : (pset[i] = findSet(pset[i]));
}

bool isSameSet(int i, int j){
	return findSet(i) == findSet(j);
}

void unionSet(int i, int j){
	pset[findSet(i)] = findSet(j);
}

int main(){
	vector<pair<int, ii> > EdgeList;
	int E, V, weight, a, b, k, n;
	char c;
	string s;
	while(scanf("%d",&V) && V){
		EdgeList.clear();
		E = 0;
		scanf("%c",&c);
		for(int z=1; z<V; z++){
			scanf("%c",&c);	
			a = c - 'A';
			//printf("vertex %c\n",c);
			scanf("%d", &k);
			for(int x=0; x<k; x++){
				scanf("%c",&c);
				scanf("%c",&c);
				//printf("%c -> %c ",a+65,c);
				b = c - 'A';
				scanf("%d",&weight);
				//printf("weight %d\n",weight);
				EdgeList.push_back(make_pair(weight, ii(a,b)));
				E++;
			}
			scanf("%c",&c);
		}
		//working
		sort(EdgeList.begin(), EdgeList.end());
		int mst_cost = 0;
		initSet(V);
		for(int i=0; i<E; i++){
			pair<int, ii>front = EdgeList[i];
			if(!isSameSet(front.second.first, front.second.second)){
				mst_cost += front.first;
				unionSet(front.second.first, front.second.second);
			}
		}
		printf("%d\n",mst_cost);
	}
	return 0;
}
