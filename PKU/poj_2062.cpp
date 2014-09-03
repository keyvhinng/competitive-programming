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

#define MAX_V 60
const int INF = 2e9+9;

int res[MAX_V][MAX_V], mf, f, s, t;
vi p;
vi adj;

void augment(int v, int minEdge){
	if(v==s){ f=minEdge; return;}
	else if(p[v]!=-1){
		augment(p[v],min(minEdge,res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f; 
	}
}

int getval(char c){
	if(isdigit(c)){
		return c-'0';
	}else{
		switch(c){
			case 'T':
				return 10;
				break;
			case 'J':
				return 11;
				break;
			case 'Q':
				return 12;
				break;
			case 'K':
				return 13;
				break;
			case 'A':
				return 14;
				break;
		}
	}
	return -1;
}

int getval2(char c){
		switch(c){
			case 'C':
				return 1;
				break;
			case 'D':
				return 2;
				break;
			case 'S':
				return 3;
				break;
			case 'H':
				return 4;
				break;
		}
		return -1;
}

bool win(string e, string a){
	int val1 = getval(e[0]);
	int val2 = getval(a[0]);
	if(val1!=val2){
		return val1>val2;
	}else{
		return getval2(e[1]) > getval2(a[1]);
	}
}

int main(){
	string card;
	int ncases, n, k;
	scanf("%d",&ncases);
	while(ncases--){
		vector<string> da, de;
		scanf("%d",&k);
		REP(i,k){
			cin>>card;
			da.pb(card);
		}
		REP(i,k){
			cin>>card;
			de.pb(card);
		}
		memset(res,0,sizeof(res));

		s = 0;
		t = 2*k+1;

		//source to deck eve
		for(int i=1; i<=k; i++){
			res[0][i] = 1;
		}
		//deck adam to tink
		for(int i=k+1; i<=2*k; i++){
			res[i][2*k+1] = 1;
		}
		//eve to adam
		for(int i=0; i<k; i++){
			for(int j=0; j<k; j++){
				if(win(de[i],da[j]))
					res[1+i][2*k+j] = 1;
			}
		}
		mf = 0;
		while(1){
			f = 0;
			vi dist(MAX_V, INF); dist[s]=0; queue<int>q; q.push(s);
			p.assign(MAX_V,-1);
			while(!q.empty()){
				int u = q.front(); q.pop();
				if(u==t) break;
				for(int v=0; v<MAX_V; v++)
					if(res[u][v]>0 && dist[v]==INF)
						dist[v] = dist[u] + 1, q.push(v), p[v]=u;
			}
			augment(t,INF);
			if(f==0) break;
			mf += f;
		}
		printf("%d\n",mf);
	}
	return 0;
}


