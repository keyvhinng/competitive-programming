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

bitset<10000010> bs;
vi primes;

void sieve(int64 n){
	bs.set();
	bs[0] = bs [1] = 0;
	for(int64 i=2; i<=n; i++)
		if(bs[i]){
			for(int64 j=i*i; j<=n; j+=i) bs[j]=0;
			primes.pb((int)i);
		}
}

int main(){
	int n, k;
	sieve(10000000);
	scanf("%d",&n);
	while(n--){
		scanf("%d",&k);
		printf("%d\n",primes[k-1]);
	}
	return 0;
}


