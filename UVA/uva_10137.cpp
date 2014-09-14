//UVA 10137 The Trip
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <math.h>
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

#define EPS 1e-9

typedef long long ll;
typedef pair<int, int> pii;


double myround(double x, int precision){ 
	return floor(x*pow(10.0,(double)precision)+0.5)/pow(10.0,(double)precision); 
} 

int main(){
	int n;
	double s, g, ans, dif, avg, l, u;
	double arr[1001];
	while(scanf("%d",&n) && n){
		s = 0;
		ans = 0;
		f(i,0,n){
			scanf("%lf",&arr[i]);
			s += arr[i];
		}
		//printf("sum %.3lf\n",s);
		avg = myround((s/n),2);
		u = l = 0;
		//printf("s: %.2lf\n",s);
		f(i,0,n){
			if(arr[i]<avg)
				l += avg - arr[i];
			if(arr[i]>avg)
				u += arr[i] - avg;
		}
		if (u == 0)
			u = l;
		if (l ==0)
			l = u;
		printf("$%.2lf\n",myround(((l<u)?l:u),2));
	}
	return 0;
}
