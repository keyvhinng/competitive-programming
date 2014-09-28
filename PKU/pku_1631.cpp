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

int n;
vector<int> vec;

int main(){
	int ncases, num;
	scanf("%d",&ncases);
	while(ncases--){
		vec.clear();
		scanf("%d",&n);
		REP(i,n){
			scanf("%d",&num);
			vec.push_back(num);
		}
		vector<int> ans;
		vector<int>::iterator it;
		REP(i,n){
			it = lower_bound(ans.begin(),ans.end(),vec[i]);
			if(it==ans.end()) ans.push_back(vec[i]);
			else *it = vec[i];
		}
		printf("%d\n",(int)ans.size());
	}
}

