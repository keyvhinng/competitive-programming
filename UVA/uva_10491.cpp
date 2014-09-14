
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
	int num, den, ncows, ncars, nshow, t;
	double ans;
	while(scanf("%d %d %d",&ncows, &ncars, &nshow)==3){
		t = ncars + ncows;
		num = (double)(ncows * ncars + ncars*(ncars-1));
		den = (double)(t*(t-nshow-1));
		ans = 	(double)(ncows * ncars + ncars*(ncars-1))/(double)(t*(t-nshow-1));
		//printf("num %d\n",num);
		//printf("den %d\n",den);
		printf("%.5lf\n",ans);
	}
	return 0;
}
