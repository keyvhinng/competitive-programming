//UVA 10130
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

int arrp[1010], arrw[1010];
//  dp[w][p]
int dp[1001][31], mw[101];

int shop(int nobj, int g){
	int ans, maxw, sum;
	sum = 0;
	ans = 0;
	maxw = 0;
	for(int i=1; i<=g; i++){
		if(maxw<mw[i]){
			maxw = mw[i];
		}
	}
	for(int i=0; i<=nobj; i++){
		// w = 0
		dp[i][0] = 0;
	}
	for (int w=0; w<=maxw; w++){
		// obj = 0
		dp[0][w] = 0;
	}
	for (int i=1; i<=nobj; i++){
		for(int w=1; w<=maxw; w++){
			if(arrw[i]>w){
				dp[i][w] = dp[i-1][w];
			}else{
				dp[i][w] = max(dp[i-1][w], arrp[i] + dp[i-1][w-arrw[i]]);
			}
		}
	}
	for (int i = 1; i<=g; i++){
		sum += dp[nobj][mw[i]];
	}
	return sum;
}

int main(){
	int t, nobj, g, my_w, ans;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&nobj);
		f(i,1,nobj+1){
			scanf("%d %d",&arrp[i], &arrw[i]);
		}
		scanf("%d",&g);
		f(i,1,g+1){
			scanf("%d",&mw[i]);
		}
		printf("%d\n",shop(nobj,g));
	}
	return 0;
}
