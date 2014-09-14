//UVA 231 Testing the CATCHER
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

int patt[100000], dp[100000], cont;

int solve(int i){
	int ans, max_ans;
	if(dp[i]!=-1)
		return dp[i];
	max_ans = 1;
	f(r,i+1,cont+1){
		if(patt[i]>=patt[r]){
			ans = 1 + solve(r);
			if(ans>max_ans)
				max_ans = ans;
		}	
	}
	return dp[i] = max_ans;
}

int main(){
	int n_test, n, max_len, res;
	scanf("%d",&n);
	n_test = 1;
	while(n!=-1){
		//initialize dp
		//memset(dp,-1,sizeof dp);
		f(i,0,100000)
			dp[i] = -1;
		cont = 1;
		patt[cont] = n;
		while(1){
			scanf("%d",&n);
			if(n==-1)
				break;
			cont++;
			patt[cont] = n;

		}
		//printf("pattern\n");
		//f(i,1,cont+1){
		//	cout<<patt[i]<<endl;
		//}
		//printf("cont %d\n",cont);
		max_len = 0;
		f(i,1,cont+1){
			res = solve(i);
			if(res>max_len){
				max_len = res;
			}
		}
		if(n_test!=1)
			printf("\n");
		printf("Test #%d:\n",n_test);
		printf("  maximum possible interceptions: %d\n",max_len);
		scanf("%d",&n);
		n_test++;
	}
	return 0;
}
