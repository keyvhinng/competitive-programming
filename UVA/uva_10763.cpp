//UVA 10763
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
	int arr[500001];
	int arr2[500001];
	int cont, u, v, eq, n;
	while(scanf("%d",&n) && n){
		for(int i=0; i<n; i++){
			scanf("%d %d", &arr[i], &arr2[i]);
		}	
		sort(arr,arr+n);
		sort(arr2,arr2+n);
		eq = 1;
		for(int i=0; i<n; i++){
			if(arr[i] != arr2[i]){
				eq = 0;
				break;
			}
		}
		if(eq)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
