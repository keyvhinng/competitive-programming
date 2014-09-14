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

vector<VI> AdjList;

int visited[26], V;
int topoSort[26];
int in[26];
map<int, char> m2;

void backtrack(int s){
	if(s==V){
		f(i,0,V){
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
	int cont;
	char c, b, a;
	string lin;
	istringstream is2;
	int flag;
	flag = 1;
	map<char,int>::iterator it;
	while(getline(cin,lin)){
		vector<char> vc;
		m2.clear();
		if(flag) flag=0;
		else printf("\n");
		memset(visited,0,sizeof(visited));
		memset(in,0,sizeof(in));
		istringstream is(lin);
		AdjList.clear();
		map<char, int> m;
		cont = 0;
		while(is>>c){
			vc.pb(c);
		}
		sort(vc.begin(),vc.end());
		f(i,0,vc.size()){
			m[vc[i]] = cont++;
		}
		for(it=m.begin(); it!=m.end(); it++){
			m2[(*it).second] = (*it).first;
		}
		V = cont;
		AdjList.assign(V,VI());
		getline(cin,lin);
		istringstream is2(lin);
		while(is2>>a>>b){
			//printf("edge %d %d\n",m[a]
			AdjList[m[a]].pb(m[b]);
			in[m[b]]++;
		}
		backtrack(0);
	}

	return 0;
}

