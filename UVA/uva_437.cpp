//UVA 437 The Tower of Babylon
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

typedef long long ll;
typedef pair<int,int> pii;

vector< pair<int,int> >vp;
vector<int> vh;
int dp[200];

int solve(int s){
	int ans, r;
	if(dp[s]!=-1)
		return dp[s];
	ans = vh[s];
	f(i,0,vp.size()){
		if((vp[i].first>vp[s].first)&&(vp[i].second>vp[s].second)){
			//printf("first : %d > %d second: %d > %d\n",vp[i].first
			r = vh[s] + solve(i);
			if(ans<r)
				ans = r;
		}
	}
	return dp[s] = ans;
}

int main(){
	int ans, n, x, y ,z, a, b, c, ncase, max;
	ncase = 1;
	while(scanf("%d",&n) && n){
		//clear vector
		vp.clear();
		vh.clear();
		//fill dimensions and corresponding heights
		f(i,0,n){
			scanf("%d %d %d",&a, &b, &c);
			vp.pb(mp(a,b));
			vh.pb(c);
			vp.pb(mp(a,c));
			vh.pb(b);
			vp.pb(mp(b,a));
			vh.pb(c);
			vp.pb(mp(b,c));
			vh.pb(a);
			vp.pb(mp(c,a));
			vh.pb(b);
			vp.pb(mp(c,b));
			vh.pb(a);
		}
		//printf("size of vp = %d\n",vp.size());
		//printf("size of vh = %d\n",vh.size());
		//initialize dp
		memset(dp,-1,sizeof dp);
		//run dp
		max = 0;
		//printf("limit solve(i) = %d\n",n*6);
		f(i,0,n*6){
			ans = solve(i);
			if(ans>max)
				max = ans;	
		}
		printf("Case %d: maximum height = %d\n",ncase,max);
		ncase++;
	}

	return 0;
}
