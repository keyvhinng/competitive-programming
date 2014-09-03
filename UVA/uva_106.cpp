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

char ss[1000010];

int  gcd(int64 a, int64 b){
	while(b){
		a %= b;
		swap(a,b);
	}
	return a;
}

int main(){
	int64 m, n, x, y, z, k, r, s, cont, up, np;
	while(scanf("%lld",&n)==1){
		cont=0; np=0;
		m = (int64)sqrt(n);
		if(m*m<n) m++;
		for(r=1; r<=m; r++){
			up = min(n-r*r,r-1);
			for(s=1; s<=up; s++){
				x = r*r - s*s;
				y = 2*r*s;
				z = r*r + s*s;
				if(z<=n){
					if(gcd(x,y)==1){
						cont++;
						for(k=1; k*z<=n; k++){
							ss[k*x] = 1;
							ss[k*y] = 1;
							ss[k*z] = 1;
						}
					}
				}
			}
		}
		for(k=1; k<=n; k++){
			if(ss[k]==0) np++;
			ss[k]=0;
		}
		printf("%lld %lld\n",cont, np);
	}
	return 0;
}

