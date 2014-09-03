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

int gu[50], an[50];

bool valid(int n){
	if(n>=1 && n<=1000000000) return true;
	return false;
}

int main(){
	int ncases, a, b, ans, l;
	scanf("%d",&ncases);
	while(ncases--){
		int c1,c2,a,b,ans,l;
		c1 = c2 = 0;
		scanf("%d",&l);
		REP(i,l) scanf("%d",&gu[i]);
		scanf("%d",&l);
		REP(i,l) scanf("%d",&an[i]);
		a = gu[0]-an[0];
		b = gu[0]+an[0];
		ans = 0;
		if(l>1){
			for(int i=1; i<l; i++){
				int p1 = gu[i]-an[i];
				int p2 = gu[i]+an[i];
				if(p1==a && p2==b) continue;
				int flag=1;
				if(p1==a || p2==a) {b=-1; flag=0;}
				if(p1==b || p2==b) {a=-1; flag=0;}
				if(flag){
					ans = -2;
					break;
				}
			}
		}else{
			if(valid(a) && valid(b)) 
				ans = -1;
			else if(valid(a))
				ans = a;
			else if(valid(b))
				ans = b;
			else
				ans = -2;
		}
		if(!ans){
			if(!valid(a)) a = -1;
			if(!valid(b)) b = -1;
			
			if(a!=-1 || b!=-1){
				if(a!=-1 && b!=-1) ans = -1;
				else if(a!=-1) ans = a;
				else ans = b;
			}else{
				ans = -2;
			}
		}	
		printf("%d\n",ans);
	}
	return 0;
}


