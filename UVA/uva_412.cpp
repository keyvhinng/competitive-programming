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

int gcd(int a, int b){
	while(b){
		a %= b;
		swap(a,b);
	}
	return a;
}

int arr[50];

int main(){
	double ans, den;
	int i, j, n, num;
	while(scanf("%d",&n) && n){
		REP(i,n)	scanf("%d",&arr[i]);
		num = 0;
		for(i=0; i<n; i++) for(j=i+1; j<n; j++)
			if(gcd(arr[i],arr[j])==1){
				num++;
			}
		if(num){
			den = (n*(n-1))/2.0;
			ans = sqrt((6*den)/num);
			printf("%lf\n",ans);
		}
		else printf("No estimate for this data set.\n");
	}
	return 0;
}


