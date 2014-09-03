#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>

#define MAX 1000000

#define f(i,x,y) for(int i=x; i<y; i++)
#define REP(i,n) for(int i=0; i<(n); i++)
#define pb push_back
#define mp make_pair


using namespace std;

typedef vector<int> VI;
typedef pair<int,int> II;

vector<VI> adjList;

struct Point{
	int id, x, y, z;

	Point(int _id, int _x, int _y, int _z){
		id = _id;
		x = _x;
		y = _y;
		z = _z;
	}

	double dist(int m, int p, int q){
		double ans;
		ans = (m-x)*(m-x)+(p-y)*(p-y)+(q-z)*(q-z);
		ans = sqrt(ans);
		return ans;
	}

};

int main(){
	int N, id, x, y, z, cont, idmin;
	double minDist;
	vector<Point> vp;
	while(scanf("%d",&N) && N){
		vp.clear();
		map<int,int> m;
		map<int,int> m2;
		cont = 0;
		adjList.assign(N,VI());
		scanf("%d%d%d%d",&id,&x,&y,&z);
		vp.pb(Point(id,x,y,z));
		m[id] = cont;
		m2[cont] = id;
		cont++;
		f(i,1,N){
			scanf("%d%d%d%d",&id,&x,&y,&z);
			if(!m.count(id)){
				m[id] = cont;
				m2[cont] = id;
				cont++;
			}
			minDist = MAX;
			REP(j,i){
				if(minDist>vp[j].dist(x,y,z)){
					idmin = vp[j].id;
					minDist = vp[j].dist(x,y,z);
				}
			}
			//printf("link %d %d\n",id,idmin);
			adjList[m[id]].pb(m[idmin]);
			adjList[m[idmin]].pb(m[id]);
			vp.push_back(Point(id,x,y,z));
		}
		
		
		int vis[1001];
		memset(vis,0,sizeof(vis));

		//bfs
		int last;
		queue<int> q; q.push(0);
		while(!q.empty()){
			int u = q.front(); q.pop();
			vis[u] = 1;
			//printf("saco %d\n",u);
			last = u;
			REP(j,(int)adjList[u].size()){
				int v = adjList[u][j];
				if(!vis[v]) q.push(v);
			}
		}
		
		//bfs
		memset(vis,0,sizeof(vis));
		queue< pair<int,int> > q2; q2.push(mp(last,0));
		int diam = -1;
		vector<int> parent(N);
		while(!q2.empty()){
			II p = q2.front(); q2.pop();
			int u = p.first;
			if(p.second>diam){
				diam = p.second;
				last = p.first;
			}
			vis[u] = 1;
			REP(j,(int)adjList[u].size()){
				int v = adjList[u][j];
				if(!vis[v]){
					parent[v] = u ;
					q2.push(mp(v,(p.second)+1));
				}
			}
		}

		vector<int> ans;
		int v = last;
		REP(i,diam/2){
			v = parent[v];
		}
		ans.pb(m2[v]);
		if(diam%2==1){
			v = parent[v];
			ans.pb(m2[v]);
		}
		sort(ans.begin(), ans.end());
		REP(i,(int)ans.size()){
			if(i) printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
