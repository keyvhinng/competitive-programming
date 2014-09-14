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
	int arr[1000];
	int ncases, n, sum, cont;
	scanf("%d",&ncases);
	while(ncases--){
		scanf("%d",&n);
		f(i,0,n){
			scanf("%d",&arr[i]);
		}
		cont = 1;
		sum = 1 ;
		f(i,1,n){
			if(i<n-1){
				if(sum<arr[i] && (sum+arr[i]<arr[i+1])){
					sum += arr[i];
					cont++;
				}
			}else{
				if(sum<arr[i]){
					sum += arr[i];
					cont++;
				}
			}
		}
		printf("%d\n",cont);
	}
	return 0;
}
