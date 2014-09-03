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

int gcd(int a, int b, int &x, int &y){
	if(a==0){
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd(b%a,a,x1,y1);
	x = y1 - (b/a)*x1;
	y = x1;
	return d;
}

int main(){
	int a, b, d, x, y;
	while(scanf("%d%d",&a,&b)==2){
		d = gcd(a,b,x,y);
		if(a==b){
			x = 0; y = 1;
		}
		printf("%d %d %d\n",x, y, d);
	}
	return 0;
}


