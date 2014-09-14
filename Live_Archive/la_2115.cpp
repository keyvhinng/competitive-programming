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

int fun(int n){
	//printf(" f %d\n", n);
	if(n==1) return 1;
	if(n%2){
		return fun(n/2) + fun(n/2+1);
	}else
		return n/2;
}

int main(){
	int n, flag;
	flag = 1;
	while(scanf("%d",&n)==1 && n!=-1){
		if(flag) flag = 0;
		else printf("\n");
		printf("f(%d) = %d\n",n,fun(n));
	}
	return 0;
}
