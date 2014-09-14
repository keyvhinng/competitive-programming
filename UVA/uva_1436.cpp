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

#define MAX 100000
#define MIN -1

typedef long long ll;
typedef pair<int,int> pii;

vector<int> AdjList[5010];

int main(){
	int bestRoot[5010];
	int worseRoot[5010];
	int N, k, z, min, max, s, v, minB, maxB, H;
	int nbRoot, nwRoot;
	while(scanf("%d",&N)==1){
		f(i,0,N){
			AdjList[i].clear();
			scanf("%d",&k);
			f(j,0,k){
				scanf("%d",&z);
				AdjList[i].pb(z-1);
			}
		}
		min = MAX;
		max = MIN;
		nbRoot = 0;
		nwRoot = 0;
		f(i,0,N){
			H = MIN;
			map<int, int> dist;
			s = i;
			dist[s] = 0;
			queue<int> q;
			q.push(s);
			while(!q.empty()){
				int u = q.front();
				//printf("node %d has %d\n",u+1,dist[u]);
			       	q.pop();
			       	for(int j=0; j<(int)AdjList[u].size(); j++){
			       		v = AdjList[u][j];
			       		if(!dist.count(v)){
			       			dist[v] = dist[u] + 1;
			       			if(H<dist[v]){
							H = dist[v];	
						}
			       			q.push(v);
			       		}
			       }
			}
			//
			//printf("root %d | Height = %d\n",i+1, H);
			if(H<=min){
				if(H<min){
					min = H;
					nbRoot = 0;
				}
				bestRoot[nbRoot] = i+1;
				nbRoot++;
			}
			if(H>=max){
				if(H>max){
					max= H;
					nwRoot = 0;
				}
				worseRoot[nwRoot] = i+1;
				nwRoot++;
			}
		}
		printf("Best Roots  :");
		f(i,0,nbRoot){
			printf(" %d",bestRoot[i]);
		}
		printf("\n");
		printf("Worst Roots :");
		f(i,0,nwRoot){
			printf(" %d",worseRoot[i]);
		}
		printf("\n");
	}
	return 0;
}
