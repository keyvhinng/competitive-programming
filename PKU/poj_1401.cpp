//P0J 1401 Factorial
#include <cassert>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <numeric>
#include <sstream>
#include <cmath>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++)
#define FOR(it,A) for(typeof A.begin(); it!=A.end(); it++)
#define quad(x) (x)*(x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second

typedef long long ll;
typedef pair<int, int> pii;

int logn(int n, int x){
	return log10((double)x)/log10((double)n);
}

int main(){
	int t, n, ans, x;
	scanf("%d",&t);
	f(i,0,t){
		ans = 0;
		scanf("%d",&n);
		while(n>=5){
			ans += n/5;
			n /= 5;
		}
		printf("%d\n",ans);
	}
	return 0;
}
