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

int main(){
	int ncases, n, sum, ans, a, b, ma, mb;
	int arr[20001];
	scanf("%d",&ncases);
	f(k,0,ncases){
		scanf("%d",&n);
		n--;
		f(i,0,n){
		   	scanf("%d",&arr[i]);
		}
		sum = 0;
		ans = 0;
		ma = 0;
		mb = 0;
		a = 0;
		b = -1;
		f(i,0,n){
			/*
			printf("analyzing %d\n",arr[i]);
			printf("ma %d\n",ma);
			printf("mb %d\n",mb);
			*/
			sum += arr[i];
			if(sum>ans){
				ans = sum;
				a = ma;
				b = mb;
			}else if( sum==ans && (mb-ma)>(b-a)){
				ans = sum;
				a = ma;
				b = mb;
			}
			if(sum<0){ 
				sum = 0;
				ma = i + 1;
				mb = ma - 1;
			}
			mb++;
			//printf("\n");
		}
		if(ans){
			printf("The nicest part of route %d is between stops %d and %d\n",k+1,a+1,b+2);
		}else{
			printf("Route %d has no nice parts\n",k+1);
		}
	}
	return 0;
}
