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

int c[60], mat[60][60];

int main(){
	vector<pair<ii,ii> > ans;
	map< int,pair<int,int> > m;
	int n, num, cont, x, y;
	scanf("%d",&n);
	REP(i,n) scanf("%d",&c[i]);
	REP(i,n)
		REP(j,c[i]){
			scanf("%d",&num);
			mat[i][j] = num;
			m[num] = mp(i,j);
		}
	cont = 1;
	REP(i,n)
		REP(j,c[i]){
			if(mat[i][j]!=cont){
				x = m[cont].first;
				y = m[cont].second;
				ans.pb(mp(mp(i,j),mp(x,y)));
				m[mat[i][j]] = mp(x,y);
				swap(mat[i][j],mat[x][y]);	
			}
			cont++;
		}
	printf("%d\n",(int)ans.size());
	REP(i,ans.size()){
		printf("%d %d %d %d\n",ans[i].first.first+1,ans[i].first.second+1,
													ans[i].second.first+1,ans[i].second.second+1);
	}
	return 0;
}

