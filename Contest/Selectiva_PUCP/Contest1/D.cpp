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
	int ncases, l;
	vector<string> vs;
	scanf("%d",&ncases);
	while(ncases--){
		vs.clear();
		scanf("%d",&l);
		REP(i,l){
			cin>>s;
			vs.pb(s);
		}
		int flag2=0;
		for(int i=0; i<vs[0].size(); i++){
			int flag1=1;
			for(int j=0; j<vs[0].size(); j++){
				if(i==j) continue;
				int a, b;
				a = b = 0;
				for(int k=0; k<l; k++){
					if(vs[k][i]<vs[k][j]){
						a++;
					}else if(vs[k][i]>vs[k][j]){
						b++;
					}
				}
				if(a<=b){
					flag1=0;
					break;
				}
			}
			if(flag1){
				printf("%d\n",i);
				flag2=1;
				break;
			}
		}
		if(!flag2) printf("-1\n");
	}
	return 0;
}


