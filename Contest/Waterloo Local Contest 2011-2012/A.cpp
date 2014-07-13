#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#define MAX 100010

using namespace std;

class UnionFind{
	private: vector<int> p, rank, sz;
	public:
		UnionFind(int n){
			rank.assign(n,0);
			p.assign(n,0);
			sz.assign(n,1);
			for(int i=0; i<n; i++)
				p[i]=i;
		}

		int findSet(int i){
			return (p[i]==i)?i:(p[i]=findSet(p[i]));
		}

		bool isSameSet(int i, int j){return findSet(i)==findSet(j);}

		void unionSet(int i, int j){
			if(!isSameSet(i,j)){
				int x = findSet(i), y = findSet(j);
				//sz[x]+= sz[y];
				//sz[y] = sz[x];
				sz[x] += sz[y];
				sz[y] = sz[x];
				if(rank[x]>rank[y]){
					p[y]=x;
				}
				else{
					p[x] = y;
					if(rank[x]==rank[y]) rank[y]++;
				}
			}
		}

		int cSize(int i) {return sz[findSet(i)];}
};

int main(){
	int ncases, nb, cont;
	string a, b;
	scanf("%d",&ncases);
	while(ncases--){
		UnionFind uf(MAX);
		cont = 0;
		map<string, int> m;
		scanf("%d",&nb);
		while(nb--){
			cin>>a>>b;
			if(m.count(a)==0) m[a] = cont++;
			if(m.count(b)==0) m[b] = cont++;
			uf.unionSet(m[a],m[b]);
			printf("%d\n",uf.cSize(m[a]));
		}
	}
	return 0;
}
