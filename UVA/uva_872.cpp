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
#include <iomanip>
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
#define sz size

using namespace std;

typedef vector<int> VI;

map<int, char>m2;
int V;
vector<VI> AdjList;
int in[20];
int topoSort[20];
int visited[20];
int pos;

void backtrack(int s){
	if(s==V){
		pos = 1;
		f(i,0,V){
			if(i) printf(" ");
			printf("%c",m2[topoSort[i]]);
		}
		printf("\n");
		return;
	}
	f(i,0,V){
		if(in[i]==0 && visited[i]==0){
			topoSort[s] = i;
			visited[i] = 1;
			f(j,0,AdjList[i].size()) in[AdjList[i][j]]--;
			backtrack(s+1);
			visited[i] = 0;
			f(j,0,AdjList[i].size()) in[AdjList[i][j]]++;
		}
	}
}


int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	map<char,int>::iterator it;
	char c, c2;
	int ncases, cont;
	string lin, s;
	scanf("%d",&ncases);
	getchar();
	f(nc,0,ncases){
		if(nc) printf("\n");
		pos = 0;
		m2.clear();
		memset(visited,0,sizeof(visited));
		memset(in,0,sizeof(in));
		AdjList.clear();
		cont = 0;
		map<char, int>m;
		vector<char>vc;
		getchar();

		getline(cin,lin);
		stringstream is(lin);

		while(is>>c) vc.pb(c);
		sort(vc.begin(),vc.end());
		f(i,0,vc.size()) m[vc[i]]=cont++;
		V = cont;
		for(it=m.begin(); it!=m.end(); it++) 
			m2[(*it).second] = (*it).first;

		AdjList.assign(V,VI());
		getline(cin,lin);
		stringstream is2(lin);
		while(is2>>c){
			is2>>c2;
			is2>>c2;
			AdjList[m[c]].pb(m[c2]);
			in[m[c2]]++;
		}
		backtrack(0);
		if(!pos) printf("NO\n");
	}
	return 0;
}

