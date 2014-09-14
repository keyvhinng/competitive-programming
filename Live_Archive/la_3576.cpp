//LA 3576
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
	int n, w, d, r, s, dif;
	while((scanf("%d %d %d %d",&n, &w, &d, &r))==4){
		s = (n-1)*(n);
		s /= 2;
		s *= w;
		dif = s - r;
		if(dif==0)
			printf("%d\n",n);
		else{
			dif /= d;
			printf("%d\n",dif);
		}
	}
	return 0;
}
