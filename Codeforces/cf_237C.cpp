#include <algorithm>
#include <bitset>
#include <deque>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
#define clr(a, v) memset(a, v, sizeof(a))
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define REPN(i,s,n) for(int i=s;i<(int)(n);i++)
#define REP(i,n) REPN(i,0,n)
#define REPIT(i,x) for( typeof x.begin()  i=x.begin(); i!=x.end(); i++ )
#define trace(x)    cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;

using namespace std;

typedef long long int64;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <string> vs;
typedef vector <ii> vii;

const int INF = 2e9+9;

bitset<1000010> prime;
int acum[1000010];
vi primes;

int a, b, k;

void sieve(int n){
	prime.set();
	prime[0] = prime[1] = 0;
	for(int i=2; i<=n; i++){
		if(prime[i]){
			primes.pb(i);
			if(i*1ll*i<=n)
				for(int j=i*i; j<=n; j+=i)
					prime[j] = 0;
		}
	}
	return;
}

bool f(int l){
	for(int x=a; x<=b-l+1; x++){
		if(acum[x+l-1]-acum[x-1]<k) return 0;
	}
	return 1;
}

int main(){
	sieve(1000010);
	acum[0] = 0;
	for(int i=1; i<1000010; i++) acum[i]=acum[i-1]+prime[i];
	scanf("%d%d%d",&a,&b,&k);
	int hi,lo, mi;
	if(acum[b]-acum[a-1]<k) printf("-1\n");
	else{
		hi = b-a+1;
		lo = 1;
		while(lo<hi){
			mi = (lo+hi)/2;
			if(f(mi)){
				hi = mi;
			}else{
				lo = mi+1;
			}
		}
		printf("%d\n",hi);
	}
	return 0;
}


