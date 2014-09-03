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
#define REP(i,n) FORN(i,0,n)
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

int64 dp[200010];

int64 phi(int n){
	int64 i;
	int64 result = n;
	for(i=2; i*i<=n; i++){
		if(n%i==0){
			while(n%i==0) n /= i;
			result -= result/i;
		}
	}
	if(n>1) result -= result/n;
	return result;
}


int main(){
	int lo, hi, i, num, mid, den, cont;
	int64 k;
	dp[0]=1;
	for(i=1; i<=200000; i++) dp[i] = dp[i-1] + phi(i);
	while(scanf("%lld",&k) && k){
		//search denominator
		lo = 1; hi = 200000;
		while(hi>lo){
			mid = (lo+hi)/2;
			if(dp[mid]>=k){
				hi = mid;
			}else{
				lo = mid+1;
			}
		}
		num = hi;
		k -= dp[num-1];
		cont = 0;
		den = 0;
		for(i=1; i<=num; i++){
			if(__gcd(i,num)==1) cont++;
			if(cont==k){
				den = i;
				break;
			}
		}
		printf("%d/%d\n",den,num);
	}
	return 0;
}


