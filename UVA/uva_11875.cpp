//UVA 11875
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cmath>
#include <cassert>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i=x; i<y; i++)
#define FOR(it,A) for(typeof A.begin(); it!=A.end(); it++)
#define quad(x) (x)*(x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second

typedef long long ll;
typedef pair<int,int> pii;

int main(){
	int arr[11];
	int t, n, ans, b;
	scanf("%d",&t);
	f(m,1,t+1){
		scanf("%d",&n);
		f(i,0,n){
			scanf("%d",&arr[i]);
		}
		ans = n/2;
		//cout<<"ans "<<ans<<endl;
		printf("Case %d: %d\n",m,arr[ans]);
	}
	return 0;
}
