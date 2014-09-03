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

int x[50], y[50];

int main(){
	int ncases, m, flag0, flag1;
	scanf("%d",&ncases);
	while(ncases--){
		int l;
		scanf("%d",&l);
		REP(i,l) scanf("%d",&x[i]);
		scanf("%d",&l);
		REP(i,l) scanf("%d",&y[i]);
		scanf("%d",&m);
		flag0 = flag1 = 0;
		for(int i=0; i<l; i++){
			if( (abs(x[i])+abs(y[i]))%2==0 ) flag0=1;
			for(int j=i+1; j<l; j++){
				if( (abs(x[i]-x[j]) + abs(y[i]-y[j]))%2==1) flag1=1;
			}
		}
		if(flag1 || (flag0!=m) ) printf("CAN\n");
		else printf("CANNOT\n");
	}
	return 0;
}


