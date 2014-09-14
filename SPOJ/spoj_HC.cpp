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
typedef pair<int, int> II;
typedef vector<II> VII;


int main(){
	int arr[100001], a, b;
	int ncases, n;
	string s;
	scanf("%d",&ncases);
	while(ncases--){
		scanf("%d",&n);
		for(int i=0; i<n; i++){
			cin>>s;
			if(s[0]=='l')
				arr[i] = 0;
			else
				arr[i] = 1;
		}
		a = arr[0];
		for(int i=1; i<n; i++){
			b = arr[i];
			if(a==b){
				a = 1;
			}else
				a = 0;
		}
		if(a)
			printf("hhb\n");
		else
			printf("lxh\n");
	}
	return 0;
}
