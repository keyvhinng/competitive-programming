//SPOJ CADYDIST
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

int main(){
	long long int n;
	long long int arrc[100010], arrp[100010];
	long long int ans;
	while(scanf("%lld",&n) && n){
		ans = 0;
		f(i,0,n){
			scanf("%lld",&arrc[i]);
		}
		f(i,0,n){
			scanf("%lld",&arrp[i]);
		}
		sort(arrc,arrc+n);
		reverse(arrc,arrc+n);
		sort(arrp,arrp+n);
		f(i,0,n){
			ans += arrc[i]*arrp[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
