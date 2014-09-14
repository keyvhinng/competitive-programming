//UVA 168 Theseus and the Minotaur
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

#define N 26 //max caverns 
#define MAX 300

typedef long long ll;
typedef pair<int,int> pii;

int k;

int go(int M, int T, int step, vector<int>adj[MAX], bool candle[MAX]){
	candle[M] = !((++step)%k);
	for(size_t v=0; v<adj[M].size(); v++){
		if(!candle[adj[M][v]] && adj[M][v] != T){
			if(candle[M])
				cout<<char(M)<<" ";
			return go(adj[M][v], M, step, adj, candle);
		}
	}
	cout<<"/"<<char(M)<<endl;
	return 0;
}

int main(){
	string line;
	while(getline(cin,line) && line!="#"){
		bool vis[MAX];
		vector<int> adj[MAX];
		size_t s, t, i, ei = 0;
		int e[2];
		string tmp = "";
		for (i = 0; i<line.size(); i++){
			if(line[i]=='.') break;
			if(line[i]==':' || line[i] ==';')
				ei = line[i] == ':' ? 1 : 0;	
			else{
				e[ei] = line[i];
				if(ei==1)
					adj[e[0]].pb(e[1]);
			}
		}
		i++;
		while(line[i]==' ')
			i++;
		s = line[i++];
		while(line[i]==' ')
			i++;
		t = line[i++];
		while(line[i]==' ')
			i++;
		k=0;
		while(i<line.size()){
			k *= 10;
			k += line[i++] - '0';
		}
		memset(vis,0,sizeof(vis));
		go(s,t,0,adj,vis);
	}
	return 0;
}
