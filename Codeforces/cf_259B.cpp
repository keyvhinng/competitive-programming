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

int arr[100010];

int main(){
	vector<int> v;
	int n, mpos, i, ans;
	scanf("%d",&n);
	for(i=0; i<n; i++) scanf("%d",&arr[i]);
	mpos = 0;
	for(i=1; i<n; i++){
		if(arr[i]<arr[i-1]){
			mpos = i;
		}
	}
	for(i=mpos; i<n; i++) v.pb(arr[i]);
	for(i=0; i<mpos; i++) v.pb(arr[i]);
	sort(arr,arr+n);
	int flag = 1;
	for(i=0; i<n; i++)
		if(arr[i]!=v[i]){
			flag=0;
			break;
		}
	if(flag){
		ans = n - mpos;
		if(ans==n) ans = 0;
	}else{
		ans = -1;
	}
	printf("%d\n",ans);
	return 0;
}


