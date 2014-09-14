//UVA 200
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
#include <list>
#include <stack>
#include <bitset>
#include <functional>
#include <utility>
#include <sstream>
#include <cctype>
#include <ctime>

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


typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

int alpha[28];
VI AdjList[28];
VI IAdjList[28];
VI topoSort;
int dfs_num[28];

void dfs2(int u){
	int v;
	dfs_num[u] = 1;
	for(int j=0; j<AdjList[u].size(); j++){
		v = AdjList[u][j];
		if(dfs_num[v]==-1)
			dfs2(v);
	}
	topoSort.pb(u);
}

int main(){
	string s, ps;
	int r;
	while(cin>>s){
		//init
		topoSort.clear();
		for(int i=0; i<26; i++){
			AdjList[i].clear();
			IAdjList[i].clear();
			dfs_num[i] = -1;
			alpha[i] = 0;
		}
		ps = "";
		//work
		while(s!="#"){
			for(int i=0; i<s.size(); i++)
				alpha[s[i]-'A'] = 1;
			if(ps.size()>0){
				r = 0;
				while(r<ps.size() && r<s.size() && ps[r] == s[r]){ r++;
					//printf("compare %c with %c\n",ps[r],s[r]);
				}
				//printf("r %d\n",r);
				//printf("fl %c\n",s[r]);
				if(r<ps.size() && r<s.size()){
					AdjList[ps[r]-'A'].pb(s[r]-'A');
					IAdjList[s[r]-'A'].pb(ps[r]-'A');
				}
			}
			ps = s;
			cin>>s;
		}
		//toposort
		for(int i=0; i<26; i++){
			if(alpha[i]){
				if(dfs_num[i] == -1 && (IAdjList[i].size()==0))
					dfs2(i);
			}
		}
		reverse(topoSort.begin(), topoSort.end());
		for(int i=0; i<topoSort.size(); i++)
			printf("%c",topoSort[i] + 65);
		printf("\n");
	}
	
	return 0;
}
