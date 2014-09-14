#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef vector<int> VI;

class UnionFind{
	private:
		int numDisSet;
		VI p, rank, size; 
	public:
		UnionFind(int N){
			numDisSet = N;
		 	rank.assign(N,0);
			p.assign(N, 0);
			size.assign(N, 1);
			for(int i=0; i<N; i++){
				p[i] = i;
			}
		}

		int findSet(int i){
			return (p[i]==i) ? i : (p[i] = findSet(p[i]));
		}

		bool isSameSet(int i, int j){
			return findSet(i) == findSet(j);
		}

		void unionSet(int i, int j){
			if(!isSameSet(i, j)){
				int x = findSet(i);
				int	y = findSet(j);
				if(rank[x]>rank[y]){
					p[y] = x;
				}else{
					p[x] = y;
					if(rank[x]==rank[y]) rank[y]++;
				}
				numDisSet--;
				size[x] += size[y];
			   	size[y] = size[x];	
			}
		}

		int numDisjoinSet(){
			return numDisSet;
		}

		int sizeOfSet(int i){
			return size[i];
		}
};

int main(){
	int max, ncases, n, m, a, b;
	string s;
	scanf("%d",&ncases);
	while(ncases--){
		scanf("%d%d",&n,&m);
		UnionFind uf(n);
		for(int i=0; i<m; i++){
			scanf("%d%d",&a,&b);
			uf.unionSet(a-1,b-1);
		}
		max = 0;
		for(int i=0; i<n; i++){
			if(max<uf.sizeOfSet(i)){
				max = uf.sizeOfSet(i);
			}
		}
		cout<<max<<endl;
	}
	return 0;
}
