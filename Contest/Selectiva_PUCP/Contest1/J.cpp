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
	string s;
	int ncases, nr, nl, nq, cont;
	scanf("%d",&ncases);
	while(ncases--){
		nr = nl = nq = 0;
		cin>>s;
		REP(i,s.size()){
				if(s[i]=='L') nl++;
				else if(s[i]=='R') nr++;
				else nq++;
		}
		int ans1=-INF;
		int ans2=-INF;
		int ans;

		cont=0;
		REP(i,s.size()){
			if(s[i]=='R') cont++;
			else if(s[i]=='L') cont--;
			else cont++;
			ans1 = max(ans1,cont);
		}
		
		cont=0;
		REP(i,s.size()){
			if(s[i]=='L') cont++;
			else if(s[i]=='R') cont--;
			else cont++;
			ans2 = max(ans2,cont);
		}
		ans = max(ans1,ans2);
		printf("%d\n",ans);
	}
	return 0;
}


