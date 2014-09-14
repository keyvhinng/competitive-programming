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
		VI p, rank; 
	public:
		UnionFind(int N){
			numDisSet = N;
		 	rank.assign(N,0);
			p.assign(N, 0);
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
			}
		}

		int numDisjoinSet(){
			return numDisSet;
		}
};

int main(){
	int ncases, n, a, b;
	string s;
	scanf("%d",&ncases);
	while(ncases--){
		cin>>s;
		cin.ignore();
		n = s[0] - 'A' + 1;
		//cout<<n<<" elements"<<endl;
		UnionFind uf(n);
		while(1){
			getline(cin,s);
			if(s=="") break;
			//cout<<s<<endl;
			a = s[0] - 'A';
			b = s[1] - 'A';
			uf.unionSet(a,b);
		}
		cout<<uf.numDisjoinSet()<<endl;
		if(ncases) cout<<endl;
	}
	return 0;
}
