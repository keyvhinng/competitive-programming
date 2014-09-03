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

int64 n, c1, n1, c2, n2, x, y;

int64 gcdext(int64 a, int64 b, int64 &x, int64 &y){
	int64 g, x1, y1;
	if(a==0){
		x = 0;
		y = 1;
		return b;
	}
	g = gcdext(b%a,a,x1,y1);
	x = y1 - x1*(b/a);
	y = x1;
	return g;
}

bool check(){
	int64 g, m1, m2, cost;
	g = gcdext(n1,n2,m1,m2);
	if(n%g!=0) return false;
	m1 *= n / g;
	m2 *= n / g;
	n2 /= g; n1 /= g;
	int64 c = ceil(-(double)m1/n2);
	int64 f = floor((double)m2/n1);
	if(c>f) return false;
	cost = c1*n2 - c2*n1;
	if(cost*c < cost * f){
		x = m1 + n2 * c;
		y = m2 - n1 * c;
	}else{
		x = m1 + n2 * f;
		y = m2 - n1 * f;
	}	
	return true;
}

int main(){
	while(scanf("%lld",&n) && n){
		scanf("%lld%lld%lld%lld",&c1,&n1,&c2,&n2);
		if(check())
			printf("%lld %lld\n",x,y);
		else
			printf("failed\n");
	}
	return 0;
}


