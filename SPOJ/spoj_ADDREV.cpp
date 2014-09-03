#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <bitset>

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> II;
typedef vector<II> VII;

int rev(int n){
	int ans;
	ans = 0;
	while(n){
		ans *= 10;
		ans += n%10;
		n   /= 10;
	}
	return ans;
}

int main(){
	int ncases, a, b;
	scanf("%d",&ncases);
	while(ncases--){
		scanf("%d %d",&a, &b);
		a = rev(a);
		b = rev(b);
		printf("%d\n",rev(a+b));
	}
  	return 0;
}

