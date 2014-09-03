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
	int ncases, flag1, flag2;
	int64 n, k, d1, d2, g1, g2;
	cin>>ncases;
	while(ncases--){
		printf("====\n");
		cin>>n>>k>>d1>>d2;
		g1 = n - k;
		g1 -= (2*d1 + d2);
		g2 = n - k;
		g2 -= (2*d2 + d1);
		flag1 = flag2 = 0;
		if(k>=(2*d1+d2)){
			if(g1>=0 && g1%3==0) flag1=1;
		}
		if(k>=(2*d2+d1)){
			printf("adsf\n");
			if(g2>=0 && g2%3==0) flag2=1;
		}
		if(flag1 || flag2) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}


