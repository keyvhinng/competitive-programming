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
typedef long long int LL;

LL _sieve_size;
bitset<10000010> bs;
VI primes;

void sieve(LL upperbound){
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(LL i=2; i<=_sieve_size; i++)
		if(bs[i]){
			for(LL j = i*i; j<=_sieve_size; j+=i)
				bs[j] = 0;
			primes.push_back((int)i);
		}
}

int main(){
	int n, count;
	sieve(40000);
	while(scanf("%d",&n) && n){
		count = 0;
		for(int i=2; i<=n/2; i++){
			if(bs[i] && bs[n-i]){
				//printf("%d %d\n",i,n-i);
				count++;
			}
		}
		printf("%d\n",count);
	}	
  	return 0;
}

