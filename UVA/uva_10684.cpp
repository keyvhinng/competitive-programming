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
	int n, sum, ans;
	int arr[10001];
	while(scanf("%d",&n) && n){
		f(i,0,n){
		   	scanf("%d",&arr[i]);
			//printf("leido %d\n",arr[i]);
		}
		sum = 0;
		ans = 0;
		f(i,0,n){
			sum += arr[i];
			ans = max(ans,sum);
			if(sum<0) sum = 0;
		}
		if(ans){
			printf("The maximum winning streak is %d.\n",ans);
		}else{
			printf("Losing streak.\n");
		}
	}
	return 0;
}
