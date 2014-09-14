#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

map<int, int> dist;

void bfs(int s, map<int,VI >AdjList){
	int u, v;
	queue<int> q;
	dist[s] = 0;
	q.push(s);
	while(!q.empty()){
		u = q.front();
		q.pop();
		for(int j=0; j<(int)AdjList[u].size(); j++){
			v = AdjList[u][j];
			if(!dist.count(v)){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}

int main(){
	int E, u, v, ttl, ncase, s, ans;
	ncase = 1;
	while(scanf("%d",&E) && E){
		//init
		map<int, vector<int> >AdjList;
		//read
		for(int i=0; i<E; i++){
			scanf("%d %d",&u, &v);
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}
	
		while(scanf("%d %d",&s, &ttl) && (s+ttl!=0)){
			map<int,int>::const_iterator it;
			dist.clear();
			bfs(s,AdjList);
			ans = 0;
			for(it = dist.begin(); it != dist.end(); ++it){
				if((*it).second>ttl) ++ans;
			}
			ans += AdjList.size() - dist.size();
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",ncase,ans,s,ttl);
			ncase++;
		}
	}
  	return 0;
}

