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

VI AdjList[27];
int dfs_num[27];
int sz;

void DFS(int u){
	int v;
	dfs_num[u] = 1;
	sz++;
	for(int j=0; j<AdjList[u].size(); j++){
		v = AdjList[u][j];
		if(dfs_num[v] == -1){
			DFS(v);
		}
	}	
	return;
}

int main(){
	string s;
	char c;
	int ncases, ntrees, nacorn;
	scanf("%d",&ncases);
	cin.ignore();
	while(ncases--){
		ntrees = 0;
		nacorn = 0;
		for(int i=0; i<27; i++){
			AdjList[i].clear();
			dfs_num[i] = -1;
		}
		while(1){
			getline(cin,s);
			if(s[0]=='*')
				break;
			//cout<<s[1]<<"-"<<s[3]<<endl;
			AdjList[s[1]-'A'].pb(s[3]-'A');
			AdjList[s[3]-'A'].pb(s[1]-'A');
		}
		getline(cin,s);
		for(int i=0; i<s.size(); i = i+2){
			if(dfs_num[s[i]-'A']==-1){
				sz = 0;
				//cout<<"DFS "<<s[i]<<endl;
				DFS(s[i]-'A');
				if(sz==1){
					nacorn++;
				}else
					ntrees++;
			}
		}
		printf("There are %d tree(s) and %d acorn(s).\n",ntrees,nacorn);
	}

	return 0;
}
