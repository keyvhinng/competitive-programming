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

const int INF = 2e9+9;

int main(){
	vector<int> v;
	int ncases, l, num, h; 
	scanf("%d",&ncases);
	while(ncases--){
		v.clear();
		scanf("%d",&l);
		REP(i,l){
			scanf("%d",&num);
			v.pb(num);
		} 
		scanf("%d",&h);
		vector< pair<int,int> > vp;
		REP(i,l){
			vp.pb(mp(abs(h-v[i]),-v[i]));
		}
		sort(vp.begin(),vp.end());
		vector<int> sol;
		printf("2\n");
		REP(i,2) sol.pb(-vp[i].second);
		sort(sol.begin(),sol.end());
		REP(i,2) printf("%d\n",sol[i]);
	}
	return 0;
}


