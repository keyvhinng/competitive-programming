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

const int INF = 2e9+9;

using namespace std;

int main(){
	long long int n, k, ans, i;
	scanf("%lld%lld",&n,&k);
	i = 1;
	ans = 0;
	while(i<=min(k,n)){
		long long int r = k % i;
		long long int q = k/i;
		long long int t = min(r/q,n-i);
		ans += r*(t+1) - q*(t+1)*t/2;
		i = i+t+1;
	}
	if(n>k) ans += k*(n-k);
	printf("%lld\n",ans);
	return 0;
}


