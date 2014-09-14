#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cmath>
#include <cassert>
#include <list>
#include <stack>
#include <bitset>
#include <functional>
#include <utility>
#include <sstream>
#include <cctype>
#include <ctime>

using namespace std;

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


typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

int coinValue[] = {10000,5000,2000,1000,500,200,100,50,20,10,5};
long long int DP[11][30001];

unsigned long long int run(int type, int value){
	unsigned long long int ans;
	if(value==0){
		return 1;
	}
	if(value<0){
		return 0;
	}
	if(type==11){
		return 0;
	}
	if(DP[type][value]!=-1){
		return DP[type][value];
	}
	ans = run(type+1,value) + run(type,value-coinValue[type]);
	return DP[type][value] = ans;
}

int main(){
	int nc, e, d, value;
	unsigned long long int ans, pot10;
	char c;
	while(1){
		scanf("%d.%d",&e,&d);
		value =	e*100 + d;
		if(value==0) break;
		//printf("value %d\n",value);
		for(int i=0; i<11; i++){
			for(int j=0; j<=value; j++){
				DP[i][j] = -1;
			}
		}
		ans = run(0,value);
		if(e<100 && e>9){
			printf(" ");
		}else if(e<10){
			printf("  ");
		}
		printf("%d.%.2d",e,d);
		pot10 = 1;
		nc = 0;
		long long int aux = ans;
		while(aux){
			aux /= 10;
			nc++;
		}
		/*
		while(ans>=pot10){
			pot10 *= 10;
			nc++;
		}
		*/
		for(int i=0; i<17-nc; i++){
			printf(" ");
		} 
		printf("%llu\n",ans);
	}
	return 0;
}

