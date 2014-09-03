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

#define MAXN 510
const int INF = 2e9+9;

int dp[MAXN][MAXN];

int gcd(int a, int b){
	while(b){
		a %= b;
		swap(a,b);
	}
	return a;
}

int main(){
	int n, i, j, ans;
	for(i=1; i<MAXN; i++) for(j=i+1; j<=MAXN; j++) dp[i][j] = gcd(i,j);
	while(scanf("%d",&n) && n){
		ans = 0;
		for(i=1; i<n; i++)
			for(j=i+1; j<=n; j++){
				ans += dp[i][j];
			}
		printf("%d\n",ans);
	}
	return 0;
}

