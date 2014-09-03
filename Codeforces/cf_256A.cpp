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
#define FOR(i,n) FORN(i,0,n)
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
	int a[3], b[3], n, need;
	int suma, sumb;
	suma = sumb = 0;
	FOR(i,3){
		scanf("%d",&a[i]);
		suma += a[i];
	}
	FOR(i,3){
		scanf("%d",&b[i]);
		sumb += b[i];
	}
	scanf("%d",&n);
	need = suma/5 + sumb/10;
	if(suma%5!=0) need++;
	if(sumb%10!=0) need++;
	if(need<=n) printf("YES\n");
	else printf("NO\n");
	return 0;
}


