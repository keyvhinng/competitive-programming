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
	int ncases, l, e, ans;
	scanf("%d",&ncases);
	while(ncases--){
		vector<string> data;
		scanf("%d",&l);
		REP(i,l){
			cin>>s;
			data.pb(s);
		}
		ans = -INF;
		for(int i=0; i<(int)data.size(); i++){
			for(int j=0; j<(int)data[0].size(); j++){
				e = min(l-i-1,(int)data[0].size()-j-1);
				for(int k=0; k<=e; k++){
					if(data[i][j]==data[i+k][j] && data[i][j]==data[i][j+k] && data[i][j]==data[i+k][j+k]){
						ans = max(ans,(k+1)*(k+1));
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}


