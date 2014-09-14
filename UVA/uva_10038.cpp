
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
	int arr[3010], dif[3010];
	int n, ans;
	while(scanf("%d",&n)==1){
		ans = 1;
		f(i,0,n){
			scanf("%d",&arr[i]);
		}
		memset(dif,0,sizeof(dif));
		f(i,1,n){
			dif[abs(arr[i]-arr[i-1])]++;
		}
		f(i,1,n){
			if(dif[i]==0){
				ans = 0;
				break;
			}
		}
		if(ans)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}
	return 0;
}
