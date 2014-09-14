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

using namespace std;

class UnionFind{
	private: vector<int> p, rank;
	public:
			 UnionFind(int N){
			 	rank.assign(N,0);
				p.assign(N,0);
				for(int i=0; i<N; i++)
					p[i] = i;
			 }

			 int findSet(int i){
			 	return (p[i]==i)?i : (p[i] = findSet(p[i]));
			 }

			 bool isSameSet(int i, int j){
			 	return findSet(i) == findSet(j);
			 }

			 void unionSet(int i, int j){
			 	if(!isSameSet(i,j)){
					int x = findSet(i), y = findSet(j);
					if(rank[x]>rank[y]){
						p[y] = x;
					}else{
						p[x] = y;
						if(rank[x]==rank[y])
							rank[y]++;
					}
				}
			 }
};

int main(){
	vector<pair<int, int> > vp;
	vector<pair<int, int> > ans;
	double dist;
	int s, ncase, n, a, b, cont, flag;
	ncase = 1;
	while(scanf("%d",&n) && n){
		UnionFind uf(n);
		printf("Network #%d\n",ncase++);
		priority_queue<pair<double, pair<int, int> > > pq;
		vp.clear();
		f(i,0,n){
			scanf("%d%d",&a,&b);
			vp.pb(mp(a,b));
		}
		f(i,0,n){
			f(j,i+1,n){
				dist = quad(vp[i].first - vp[j].first) + quad(vp[i].second - vp[j].second); 
				dist = sqrt(dist);
				pq.push( mp(-dist, mp(i,j)) );
			}
		}
		flag = 1;
		while(!pq.empty()){
			printf("%.4lf %d %d\n",pq.top().first, pq.top().second.first, pq.top().second.second);
			pq.pop();
			a = pq.top().second.first;
			b = pq.top().second.second;
			if(flag){
				uf.unionSet(a,b);
				s = a;
				flag = 0; 
				cont = 2;
			}else{
				if(!uf.isSameSet(s,a) || !uf.isSameSet(s,b)){
					ans.pb(mp(a,b));
					if(!uf.isSameSet(s,a)) cont++;
					if(!uf.isSameSet(s,b)) cont++;
					uf.unionSet(s,a);
					uf.unionSet(s,b);
				}	
			}
			if(cont==n){
				printf("EXITO\n");
				break;
			}
		}
		f(i,0,ans.size()){
			printf("%d %d\n",ans[i].first, ans[i].second);
		}
	}
	return 0;
}

