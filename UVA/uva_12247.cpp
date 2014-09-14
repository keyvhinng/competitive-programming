//UVA 12247
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
#include <list>
#include <stack>
#include <bitset>
#include <functional>
#include <utility>
#include <sstream>
#include <cctype>
#include <ctime>

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


typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

int main(){
	vector<int> v;
	int n1, n2, n3, a, b, aux, ans;
	while(scanf("%d %d %d %d %d",&n1, &n2, &n3, &a, &b) &&
		n1 && n2 && n3 && a && b){
		v.clear();
		v.pb(n1);
		v.pb(n2);
		v.pb(n3);
		sort(v.begin(), v.end());
		if(a<b) swap(a,b);
		if(b<v[1]){
			if(a<v[2]){
				printf("-1\n");
			}else{
				ans = v[2] +1;
				if(ans==a){
					ans++;
				}
				if(ans<=52){
					printf("%d\n",ans);
				}else{
					printf("-1\n");
				}
			}
			
		}else{
			if(b>v[2]){
				ans = 1;
				if(ans==v[0]){
					ans++;
				}
				if(ans==v[1]){
					ans++;
				}
				if(ans==v[2]){
					ans++;
				}
				if(ans==v[3]){
					ans++;
				}
				if(ans==a || ans==b){
					ans++;
				}
				if(ans==a || ans==b){
					ans++;
				}
				if(ans<=52){
					printf("%d\n",ans);
				}else{
					printf("-1\n");
				}
			}else{
				ans = v[1] + 1;
				if(ans==v[2] || ans==a || ans==b){
					ans++;
				}
				if(ans==v[2] || ans==a || ans==b){
					ans++;
				}
				if(ans==v[2] || ans==a || ans==b){
					ans++;
				}
				if(ans<=52){
					printf("%d\n",ans);
				}else{
					printf("-1\n");
				}
			}
		}
	}
	return 0;
}
