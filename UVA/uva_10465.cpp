#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <cmath>
#include <algorithm>
#include <ctime>

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

using namespace std;

int main(){
	int used[10001];
	int a, b, c, n, minw, ming, na, w;
	while(scanf("%d%d%d",&a,&b,&c)==3){
		//clr(used,0);
		if(a>b) swap(a,b);
		minw = 10000;
		for(int nb=0; nb<=c/b; nb++){
			na = (c-(b*nb))/a;
			w = c - (na*a+nb*b);
			if(w<minw){
				minw = w;
				n = na + nb;
			}else if(w==minw){
				n = max(n,na+nb);
			}
		}
		printf("%d",n);
		if(minw){
			printf(" %d",minw);
		}
		printf("\n");
	}
	return 0;
}
