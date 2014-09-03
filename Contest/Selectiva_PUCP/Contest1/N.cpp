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

int arr[10];

int main(){
	int ncases, num, dig;
	scanf("%d",&ncases);
	while(ncases--){
		REP(i,10) arr[i]=0;
		scanf("%d",&num);
		while(num){
			dig = num % 10;
			arr[dig]++;
			num /= 10;
		}
		int tmp = arr[6]+arr[9];
		if(tmp%2!=0) tmp++;
		tmp /= 2;
		arr[6] = tmp; 
		int maxdi = 0;
		int m = -INF;
		REP(i,9){
			if(arr[i]>m){
				m = arr[i];
				maxdi = i;
			}
		}
		printf("%d\n",m);
	}
	return 0;
}


