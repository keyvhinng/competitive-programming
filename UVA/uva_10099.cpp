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
#include <bitset>

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> II;
typedef vector<II> VII;

vector<VII> AdjList;
int dist[100];

void bfs(int s){
	queue<II> q;
	II u, v;
	q.push(make_pair(s,1<<20));
	while(!q.empty()){
		u = q.front();
		q.pop();
		for(int j=0; j<AdjList[u.first].size(); j++){
			v = AdjList[u.first][j];
			if(min(u.second,v.second)>dist[AdjList[u.first][j].first]){
				dist[AdjList[u.first][j].first] = min(u.second,v.second);
				q.push(make_pair(v.first,dist[AdjList[u.first][j].first]));
			}
		}
	}
	return;
}

int main(){
	int s, d, t, u, v, w, V, E, ncase, ans;
	ncase = 1;
	while(scanf("%d %d",&V, &E) && (V+E!=0)){
		//init
		AdjList.clear();
		//read
		AdjList.assign(V,VII());
		for(int i=0; i<E; i++){
			scanf("%d %d %d",&u, &v, &w);
			AdjList[u-1].push_back(make_pair(v-1,w));
			AdjList[v-1].push_back(make_pair(u-1,w));
		}
		scanf("%d %d %d",&s, &d, &t);
		printf("Scenario #%d\n",ncase++);
		if(s==d){
			printf("Minimum Number of Trips = 0\n\n");
			continue;
		}
		s--;
		d--;
		memset(dist, -1, sizeof dist);
		bfs(s);
		ans = (t)/(dist[d]-1);
		if((t%(dist[d]-1))!=0)
			ans++;
		printf("Minimum Number of Trips = %d\n\n",ans);
	}
  	return 0;
}

