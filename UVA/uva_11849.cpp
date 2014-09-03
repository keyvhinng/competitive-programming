#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main(){
	int n, m, t, ans;
	map<int, int> mp;
	while(scanf("%d%d",&n,&m) && (n+m!=0)){
		mp.clear();
		for(int i=0; i<n; i++){
			scanf("%d",&t);
			mp[t] = 0;
		}
		ans = 0;
		for(int i=0; i<m; i++){
			scanf("%d",&t);
			if(mp.count(t)){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
}
