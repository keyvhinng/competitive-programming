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

int n;
vector<int> primes;

bool isPrime(int n){
	f(i,0,primes.size()){
		if(n==primes[i])
			return true;
	}
	return false;
}

bool check(vector<int> v, int k){
	if(v.size()){
		f(i,0,v.size()){
			if(k==v[i]) 
				return false;
		}
		if(!isPrime(v[v.size()-1] + k)){
			return false;
		}
		if(v.size()==n-1){
			if(!isPrime(1 + k))
				return false;	
		}
	}
	return true;
}



void backtrack(vector<int> v, int r){
	if(r==n){
		f(i,0,n){
			if(i) printf(" ");
			printf("%d",v[i]);
		}
		printf("\n");
		return;
	}
	f(i,2,n+1){
		if(check(v, i)){
			v.pb(i);
			backtrack(v,r+1);	
			v.erase(v.begin()+r);
		}
	}
}

int main(){
	int flag, nc;
	vector<int> v;
	primes.pb(2);
	primes.pb(3);
	primes.pb(5);
	primes.pb(7);
	primes.pb(11);
	primes.pb(13);
	primes.pb(17);
	primes.pb(19);
	primes.pb(23);
	primes.pb(29);
	primes.pb(31);
	flag = 1;
	nc = 1;
	while(scanf("%d",&n)==1){
		if(flag){
			flag = 0;
		}else{
			printf("\n");
		}
		v.clear();
		v.pb(1);
		printf("Case %d:\n",nc++);
		backtrack(v, 1);
	}
	return 0;
}
