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

int main(){
	int i, j, n, s, e;
	scanf("%d",&n);
	s = e = n/2;
	for(i=0; i<n/2; i++){
		for(j=0  ; j<=s-1; j++) printf("*");
		for(j=s  ; j<=e  ; j++) printf("D");
		for(j=e+1; j< n  ; j++) printf("*");
		printf("\n");
		s--;
		e++;
	}
	for(i=0; i<n; i++) printf("D");
	printf("\n");
	s = 1; e = n-2;
	for(i=0; i<n/2; i++){
		for(j=0  ; j<=s-1; j++) printf("*");
		for(j=s  ; j<=e  ; j++) printf("D");
		for(j=e+1; j< n  ; j++) printf("*");
		printf("\n");
		s++;
		e--;
	}
	printf("\n");
	return 0;
}


