#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <cmath>
#include <algorithm>
#include <ctime>

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

using namespace std;

int main(){
	int b, ncases, n, p, arr[20], sum, flag;
	scanf("%d",&ncases);
	while(ncases--){
		flag = 0;
		scanf("%d",&n);
		scanf("%d",&p);
		f(i,0,p) scanf("%d",&arr[i]);
		for(b=0; b<(1<<p); b++){
			sum = 0;
			for(int j=0; j<p; j++){
				if(b & (1<<j)){
					sum += arr[j];
				}
			}
			if(sum==n){
				flag = 1;
				break;
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
