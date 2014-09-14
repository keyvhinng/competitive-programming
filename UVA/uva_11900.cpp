//UVA 11900
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
	int ncases, ans, n, p, q, c;
	int arr[35];
	scanf("%d",&ncases);
	f(i,1,ncases+1){
		//read
		scanf("%d %d %d", &n, &p, &q);
		f(j,0,n){
			scanf("%d",&arr[j]);
		}
		ans = 0;
		c = 0;
		f(j,0,n){
			//cout<<"in carry "<<c<<endl;
			c += arr[j];
			ans++;
			if(c>q || ans>p){
				c -= arr[j];
				ans--;
				break;
			}

		}
		printf("Case %d: %d\n",i,ans);
	}	
	return 0;
}
