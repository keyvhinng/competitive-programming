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

int main(){
	long long int n, _a, _b;
	double a, b, ans;
	while(scanf("%lld %lld %lld",&_a,&_b,&n) && (_a+_b+n)){
		a = _a; b = _b;
		switch(n%5){
			case 0:
				ans = a;
				break;
			case 1:
				ans = b;
				break;
			case 2:
				ans = (1+b)/a;
				break;
			case 3:
				ans = (1+a+b)/(a*b);
				break;
			case 4:
				ans = (1+a)/b;
				break;
		}
		printf("%.0lf\n",ans);
	}
	return 0;
}


