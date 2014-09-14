//SPOJ COWCAR
#include <cassert>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <numeric>
#include <sstream>
#include <cmath>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++)
#define FOR(it,A) for(typeof A.begin(); it!=A.end(); it++)
#define quad(x) (x)*(x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second

typedef long long ll;
typedef pair<int, int> pii;

int main(){
	long long int v, pos, d, l, n, m, h, ans;
	long long int arrs[50010];
	scanf("%lld %lld %lld %lld",&n, &m, &d, &l);
	f(i,0,n){
		scanf("%lld",&arrs[i]);
	}
	ans = 0;
	h = 0;
	pos = 0;
	f(i,0,n){
		if(h==m){
			h = 0;
			pos++;
		}
		v = arrs[i] - pos*d;
		if(v>=l){
			h++;
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
