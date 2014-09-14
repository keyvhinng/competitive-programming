//UVA 10131
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

struct E{
	int ind, W, S;

	E(){
	}

	E(int _ind, int _W, int _S){
		ind = _ind;
		W = _W;
		S = _S;
	}

	bool operator <(E X) const{
		if(W!=X.W) return W<X.W;
		return S>X.S;
	}
};

int main(){
	int n, w, s;
	n = 0;
	E a[1000];
	while(scanf("%d %d",&w, &s)==2) 
		a[n] = E(++n,w,s);
	sort(a,a+n);

	int dp[n], next[n], ans, start;
	ans = 0;

	for(int i=n-1; i>=0; i--){
		dp[i] = 1;
		next[i] = -1;

		for(int j=i+1; j<n; j++){
			if(a[i].W<a[j].W && a[i].S>a[j].S && 1+dp[j]>dp[i]){
				dp[i] = 1+dp[j];
				next[i] = j;
			}
		}		
		if(dp[i]>ans){
			ans=dp[i];
			start = i;
		}
	}
	printf("%d\n",ans);
	for(int i=start; i!=-1; i=next[i])
		printf("%d\n",a[i].ind);
  	return 0;
}

