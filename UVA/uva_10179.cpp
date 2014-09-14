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
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iomanip>
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
#define sz size

using namespace std;

vector<int> prime_factors(int n){
	vector<int> ans;
	for(int i=2; n>1;){
		if(n%i==0){
			for(;n%i==0;n/=i);
			ans.pb(i);
		}	
		i++;
		if(i>n/i) i=n;
	}
	/*
	if(n>1){ ans.pb(n);
		printf("n %d\n",n);
	}
	*/
	return ans;
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n, delta;
	while(scanf("%d",&n) && n){
		if(n==1){
			printf("1\n");
			continue;
		}
		vector<int> v = prime_factors(n);
		int ans=0;
		int q = v.size();
		for(int i=1; i<(1<<q); ++i){
			int p=1;
			for(int j=0; j<q; ++j){
				if(i&(1<<j)){
					p = p*v[j];
				}
			}
			delta = n/p - 1;
			if(__builtin_popcount(i)&1) {
				ans+=delta;
			}else{
				ans-=delta;
			}
		} 
		printf("%d\n",n-(ans+1));
	}
	return 0;
}

