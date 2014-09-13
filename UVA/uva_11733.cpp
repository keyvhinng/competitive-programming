#include <algorithm>
#include <bitset>
#include <deque>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
#define clr(a, v) memset(a, v, sizeof(a))
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define REPN(i,s,n) for(int i=s;i<(int)(n);i++)
#define REP(i,n) REPN(i,0,n)
#define REPIT(i,x) for( typeof x.begin()  i=x.begin(); i!=x.end(); i++ )
#define trace(x)    cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;

using namespace std;

typedef long long int64;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <string> vs;
typedef vector <ii> vii;

const int INF = 2e9+9;


int n, m, a;

class UnionFind {                                              
private:
  vi p, rank, setSize;                       
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }

  int numDisjointSets() { return numSets; }

  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main(){
	int ncases, u, v, w;
	scanf("%d",&ncases);
	for(int z=1; z<=ncases; z++){
		printf("Case #%d: ",z);
		scanf("%d%d%d",&n,&m,&a);
		vector<pair<int, pair<int,int> > > vp;
		for(int i=0; i<m; i++){
			scanf("%d%d%d",&u,&v,&w);
			u--; v--;
			vp.pb(mp(w,mp(u,v)));
		}
		sort(vp.begin(),vp.end());
		int cost=0;
		vector<int> col;
		UnionFind uf(n);
		col.assign(n,0);
		int ncon = 0;
		for(int i=0; i<(int)vp.size(); i++){
			if(vp[i].first >= a){
				break;
			}
			u = vp[i].second.first;
			v = vp[i].second.second;
			if(!uf.isSameSet(u,v)){
				ncon++;
				col[u] = 1; col[v] =1;
				uf.unionSet(u,v);
				cost += vp[i].first;
			}
		}

		int nair = uf.numDisjointSets(); 
		printf("%d %d\n",cost+a*nair,nair);
	}

	return 0;
}


