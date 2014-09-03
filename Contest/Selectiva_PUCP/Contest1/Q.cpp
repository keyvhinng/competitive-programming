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

int a[60], b[60];

int main(){
	int ncases, l;
	scanf("%d",&ncases);
	while(ncases--){
		int tot = 0;
		scanf("%d",&l);
		REP(i,l){
			scanf("%d",&a[i]);
			tot += a[i];
		}
		scanf("%d",&l);
		REP(i,l){
			scanf("%d",&b[i]);
		}
		sort(b,b+l);
		reverse(b,b+l);
		/*
		printf("--\n");
		REP(i,l){
			printf("b[] = %d\n",b[i]);
		}
		*/
		int cont=0;
		int sum=0;
		while(sum<tot){
			sum += b[cont];
			cont++;
		}
		printf("%d\n",cont);
	}
	return 0;
}


