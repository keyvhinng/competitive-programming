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
	vector<string> attendance, problemTopics, ans;
	int ncases, n, m, k2;
	scanf("%d",&ncases);
	while(ncases--){
		attendance.clear();
		problemTopics.clear();
		ans.clear();
		scanf("%d",&n);
		REP(i,n){
			cin>>s;
			attendance.pb(s);
		}
		scanf("%d",&k2);
		REP(i,k2){
			cin>>s;
			problemTopics.pb(s);
		}
		for(int i=0; i<n; i++){
			string tmp(k2,'X');
			ans.pb(tmp);
			for(int j=0; j<k2; j++){
				for(int k=0; k<attendance[0].size(); k++){
					if(problemTopics[j][k]=='X' && attendance[i][k]=='-'){
						ans[i][j] = '-';
						break;
					}
				}
			}
		}
		printf("%d\n",n);
		REP(i,ans.size()) cout<<ans[i]<<endl;
	}
	return 0;
}


