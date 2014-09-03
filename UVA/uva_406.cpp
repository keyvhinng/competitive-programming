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

vi primes;
bitset<1020> bs;

void sieve(int64 n){
	int i, j;
	bs.set();
	bs[0] = bs[1] = 0;
	primes.pb(1);
	for(i=2; i<=n; i++){
		if(bs[i]){
			primes.pb(i);
			if(i*1ll*i<=n)
				for(j=i*i; j<=n; j+=i){bs[j] = 0;}
		}
	}
}

int main(){
	int i, n, C, lo, hi, mi, ini, w;
	sieve(1010);
	while(scanf("%d%d",&n,&C)==2){
		//binary search
		lo = 0; hi = primes.size()-1;
		while(hi>lo){
			 mi = (hi+lo)/2;
			 if(n<=primes[mi]) hi = mi;
			 else lo = mi+1;
		}
		if(primes[hi]>n) hi--;
		i = hi+1;
		printf("%d %d:",n,C);
		int c = (i%2)? C*2-1 : C*2;
		int s = (i-c)>0? (i-c) / 2 : 0;
		int e = (i-c)>0? s+c : i;
		for(int j=s; j<e; j++){
			printf(" %d",primes[j]);
		}
		printf("\n\n");
	}
	return 0;
}


