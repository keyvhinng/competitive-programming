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


using namespace std;

const int INF = 2e9+9;

bitset<16000000> bs;

int main(){
	int p;
	int a, c, m, rn, ans;
	cin>>a>>c>>m>>rn;
	bs.reset();
	bs[rn] = 1;
	while(1){
		rn = (a*rn+c)%m;
		if(bs[rn]){
			break;
		}else{
			bs[rn]=1;
		}
	}
	ans = -INF;
	p = m;
	for(int i=0; i<m; i++){
		if(bs[i]){
			ans = max(ans,i-p);
			p = i;
		}
	}
	cout<<ans<<endl;
	return 0;
}

