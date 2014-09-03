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

vector<int> build(int n){
	int i;
	vector<int> ans(1,0);
	for(i=1; i<(1<<n); i++)
		ans.pb(ans.back() ^ (i & -i));
	return ans;
}

int main(){
	int n, m;
	scanf("%d%d",&n,&m);
	vi row = build(n);
	vi col = build(m);
	for(int i=0; i<(1<<n); i++)
		for(int j=0; j<(1<<m); j++)
			printf("%d%c",(row[i]<<m) | col[j], j==(1<<m) -1 ? '\n' : ' ');
	return 0;
}


