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
#define FORN(i,s,n) for(int i=s;i<(int)(n);i++)
#define REP(i,n) FORN(i,0,n)
#define FORIT(i,x) for( typeof x.begin()  i=x.begin(); i!=x.end(); i++ )
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
	int n, m, num, pos, ans, tmp;
	vi vec;
	scanf("%d%d",&n,&m);
	ans = -INF;
	REP(i,n){
		scanf("%d",&num);
		tmp = num/m;
		if(num%m!=0) tmp++;
		if(tmp>=ans){
			ans = tmp;
			pos = i+1;
		}
	}
	printf("%d\n",pos);
	return 0;
}


