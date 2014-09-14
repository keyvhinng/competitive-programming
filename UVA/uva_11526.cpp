//UVA 11526 H(n)
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

long long H(long long n){
	int r;
	r = floor((double)(sqrt(n)));
	long long res = 0;
	for(int i=1; i<=r; i++){
		res = res + 2*(floor(n/(double)i));
	}
	res -= quad(r);
	return res;
}

int main(){
	int t;
	long long n;
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		printf("%lld\n",H(n));	
	}
	return 0;
}
