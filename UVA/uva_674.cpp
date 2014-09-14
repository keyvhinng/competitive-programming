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

int coins[] = {50, 25, 10, 5, 1};
unsigned long long int DP[7500][5];

unsigned long long int run(int value,int type){
	unsigned long long int ans;
	if(value == 0){
		return 1;
	}
	if(value < 0){
		return 0;
	}
	if(type == 5){
		return 0;
	}
	if(DP[value][type]!=-1){
		return DP[value][type];
	}
	ans = run(value-coins[type],type) + run(value,type+1);
	return DP[value][type] = ans;
}

int main(){
	int n;
	for(int i=0; i<=7490; i++)
			for(int j=0; j<5; j++){
				DP[i][j] = -1;	
			}
	while(scanf("%d",&n)==1){		
		//work
		printf("%llu\n",run(n,0));
	}
  	return 0;
}

