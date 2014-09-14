// POJ 2262
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

#define EPS 1e-7

typedef long long ll;
typedef pair<int, int> pii;

bool IsPrimeSlow(ll x){
	if(x<=1) return false;
	if(x<=3) return true;
	if (!(x%2) || !(x%3)) return false;
	ll s = (ll) (sqrt((double)(x))+EPS);
	for (ll i=5; i<=s; i+=6){
		if( !(x%i) || !(x%(i+2)) )
			return false;
	}
	return true;
}


int main(){
	int n;
	ll n1, n2;
	n1 = 3;
	while(scanf("%d",&n) && n!=0){
		n1 = 3;
		n2 = n - n1;
		while(!IsPrimeSlow(n1) || !IsPrimeSlow(n2)){
			n1++;
			n2 = n - n1;
		}
		printf("%d = %lld + %lld\n",n,n1,n2);
	}

	return 0;
}
