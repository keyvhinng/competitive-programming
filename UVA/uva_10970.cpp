//UVA 10970
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

int dp[301][301];

int run(int n, int m){
	int aux, ans, m1, m2;
	//check if it's already solved
	if(dp[n][m]!=-1){
		return dp[n][m];
	}
	// m >= n
	if(m<n){
		aux = n;
		n = m;
		m = aux;
	}	
	m1 = m/2;
	m2 = m/2 + (m%2);
	ans = 1 + run(n,m1) + run(n,m2);
	return dp[m][n] = dp[n][m] = ans;
}

int main(){
	int n, m, aux, ans;
	for(int i=0; i<301; i++){
		for(int j=0; j<301; j++){
			dp[i][j] = -1;
		}
	}

	dp[1][1] = 0;
	while(scanf("%d %d",&n ,&m)==2){
		ans = run(n,m);
		printf("%d\n",ans);
	}
	return 0;
}
