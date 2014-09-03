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

int arr[60];

int main(){
	int ncases, l, ans, a, b;
	scanf("%d",&ncases);
	while(ncases--){
		scanf("%d",&l);
		REP(i,l) scanf("%d",&arr[i]);
		if(l==1){
			ans = -1;
		}else{
			//arithm
			ans = 0 ;
			int flag1=1;
			a = arr[1]-arr[0];
			for(int i=1; i<l; i++)
				if(arr[i]-arr[i-1]!=a){
					flag1=0;
					break;
				}
			ans += flag1;
			//geo
			int flag2=0;
			if(arr[0]<=arr[1]){
				if(arr[1]%arr[0]==0){
					flag2=1;
					b = arr[1]/arr[0];
					for(int i=1; i<l; i++)
						if(arr[i]%arr[i-1]!=0 || arr[i]/arr[i-1]!=b){
							flag2=0;
							break;
						}
				}
			}else{
				if(arr[0]%arr[1]==0){
					flag2=1;
					b = arr[0]/arr[1];
					for(int i=1; i<l; i++)
						if(arr[i-1]%arr[i]!=0 || arr[i-1]/arr[i]!=b){
							flag2=0;
							break;
						}
				}
			}
			ans += flag2;
		}
		printf("%d\n",ans);
	}
	return 0;
}

