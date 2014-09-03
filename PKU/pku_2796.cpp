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


typedef pair<int64,int64> pi;


int main(){

	int arr[100010];
	int left[100010];
	int right[100010];
	int64 acum[100010];

	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&arr[i]);

	for(int i=0; i<n; i++) acum[i+1] = acum[i] + arr[i];

	left[0] = -1;
	for(int i=1; i<n; i++){
		left[i]=i-1;
		if(arr[left[i]]>=arr[i]){
			do{
				left[i] = left[left[i]];
			}while(left[i]!=-1 && arr[left[i]] >= arr[i]);
		}
	}

	right[n-1] = n;
	for(int i=n-2; i>=0; i--){
		right[i]=i+1;
		if(arr[i]<=arr[right[i]]){
			do{
				right[i] = right[right[i]];
			}while(right[i]!=n && arr[i] <= arr[right[i]]);
		}
	}
	int64 ans = -1;
	int64 tmp;
	int l, r;
	for(int i=0; i<n; i++){
		tmp = (acum[right[i]]-acum[left[i]+1])*arr[i];
		if(tmp>ans){
			ans = tmp;
			l = left[i]+2;
			r = right[i];
		}
	}
	printf("%lld\n",ans);
	printf("%d %d\n",l,r);
	return 0;
}



