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

int nextpow2(int n){
	int ans=1;
	while(n>ans) ans*=2;
	return ans;
}

int main(){
	int ncases, num, a, b;
	scanf("%d",&ncases);
	while(ncases--){
		priority_queue<int> pq;
		vector<int> v;
		int l;
		scanf("%d",&l);
		REP(i,l){
			scanf("%d",&num);
			pq.push(-nextpow2(num));
		}
		REP(i,l){
			while(pq.size()>1){
				a = pq.top(); pq.pop();
				b = pq.top(); pq.pop();
				pq.push(2*b);
			}
		}
		printf("%d\n",-pq.top());
	}
	return 0;
}


