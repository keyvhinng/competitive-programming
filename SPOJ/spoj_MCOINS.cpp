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

#define MAXN 1010
#define MAXM 4050
#define INF 0x3f3f3f3f

int DP[1000010];

int K, L;

void run(void){
	int ans1, ans2, ans3;
	for(int i=1; i<1000010; i++){
		if(DP[i-1]==0){
			DP[i] = 1;
		}else if(i>=K && DP[i-K]==0){
			DP[i] = 1;
		}else if(i>=L && DP[i-L]==0){
			DP[i] = 1;
		}
	}
}

int main(){
	int m, n;
	scanf("%d %d %d",&K, &L, &m);
	memset(DP, 0, sizeof DP);
	run();
	while(m--){
		scanf("%d",&n);
		if(DP[n]){
			printf("A");
		}else
			printf("B");
	}
	return 0;
}
