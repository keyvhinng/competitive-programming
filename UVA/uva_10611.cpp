//UVA 10611
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

typedef long long ll;
typedef pair<int,int> pii;

int main(){
	int arr[50010];
	int n, q, h, a, b, flag;
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	scanf("%d",&q);
	for(int i=0; i<q; i++){
		a = 0;
		b = 2147483647;
		flag = 0;
		scanf("%d",&h);
		for(int j=0; j<n; j++){
			if(arr[j]<h && arr[j]>a){
				a = arr[j];
			}
			if(arr[j]>h && arr[j]<=b){
				flag = 1;
				b = arr[j];
			}
		}
		if(a!=0){
			printf("%d ",a);
		}else{
			printf("X ");
		}
		if(flag){
			printf("%d\n",b);
		}else{
			printf("X\n");
		}
	}
	return 0;
}
