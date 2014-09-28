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
#include <list>
#include <stack>
#include <bitset>
#include <functional>
#include <utility>
#include <sstream>
#include <cctype>
#include <ctime>

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

#define MAXN 1005

typedef long long ll;
typedef pair<int,int> pii;

int Q[MAXN];

int main(){
	int n, m, a, b, w;
	int C, R;
	scanf("%d",&n);
	f(i,0,n){
		scanf("%d",&Q[i]);
		Q[i] = -1;
	}
	scanf("%d",&m);
	f(i,0,m){
		scanf("%d %d %d",&a,&b,&w);
		a--;
		b--;
		if(Q[b]<0 || w<Q[b])
			Q[b] = w;
	}
	R = 0;
	C = 0;
	f(i,0,n){
		if(Q[i]<0){
			C++;
		}
		else{
			R += Q[i];
		}
	}
	if(C>1)
		printf("-1\n");
	else
		printf("%d\n",R);
	return 0;
}
