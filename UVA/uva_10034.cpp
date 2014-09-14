#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

typedef pair<double, double> DD;
typedef pair<int, int> II;
typedef pair<int, double> ID;
typedef vector<int> VI;
typedef vector<II> VII;
typedef vector<ID> VID;

class UnionFind{
	private:
		VI p, rank, setSize;
		int numSets;
	public:
		UnionFind(int N){
			setSize.assign(N, 1);
			numSets = N;
			rank.assign(N, 0);
			p.assign(N, 0);
			for(int i=0; i<N; i++) p[i] = i;
		}
		
		int findSet(int i){
			return (p[i]==i) ? i : (p[i] = findSet(p[i]));
		}
		
		bool isSameSet(int i, int j){
			return findSet(i) == findSet(j);
		}
		
		void unionSet(int i, int j){
			if(!isSameSet(i,j)){
				numSets--;
				int x = findSet(i), y = findSet(j);
				//rank is used to keep the tree short
				if(rank[x] > rank[y]){
					p[y] = x; setSize[x] += setSize[y];
				}else{
					p[x] = y; setSize[y] += setSize[x];
					if(rank[x] ==rank[y]) rank[y]++;
				}
			}
		}
		
		int numDisjointSets() {return numSets;}
		int sizeOfSet(int i)  {return setSize[findSet(i)];}
};

vector<VID> AdjList;
VI taken;

double d(DD x,DD y){
	return sqrt(pow(abs(y.first - x.first),2) + pow(abs(y.second - x.second),2));
}

int main(){
	int V, E, u, v, ncases;
	double w, x, y;
	pair<double, double> coord[101];
	scanf("%d",&ncases);
	while(ncases--){
		//initialize
		AdjList.clear();
		//read coordinates
		scanf("%d", &V);
		for(int i=0; i<V; i++){
			scanf("%lf %lf",&x, &y);
			coord[i] = make_pair(x,y);
		}
		//Kruskal
		AdjList.assign(V, VID());
		vector<pair<double, II> > EdgeList;
		E = 0;
		for(int i=0; i<V; i++){
			for(int j=i+1; j<V; j++){
				E++;
				w = d(coord[i],coord[j]);
				//printf("w(%d,%d) = %.2lf\n",i,j,w);
				EdgeList.push_back(make_pair(w,II(i,j)));
				AdjList[i].push_back(ID(j,w));
				AdjList[j].push_back(ID(i,w));
			}
		}
		sort(EdgeList.begin(), EdgeList.end());	
		double mst_cost = 0;
		UnionFind UF(V);
		for(int i=0; i<E; i++){
			pair<double, II> front = EdgeList[i];
			if(!UF.isSameSet(front.second.first, front.second.second)){
				mst_cost += front.first;
				UF.unionSet(front.second.first, front.second.second);
			}		
		}
		printf("%.2lf\n",mst_cost);
		if(ncases){
			puts("");
		}
	}
	return 0;
}
