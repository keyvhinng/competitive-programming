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
typedef pair<int, int> PII;
typedef vector<PII> VPII;


int main(){
	int ncases, n, k, p, ans;
	scanf("%d",&ncases);
	for(int i=1; i<=ncases; i++){
		scanf("%d %d %d",&n, &k, &p);
		ans = (k+p-1)%n;
		printf("Case %d: %d\n",i,ans+1);
	}
  	return 0;
}

