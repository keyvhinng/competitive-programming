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
	int s, c, ncases, no, ne, ans;
	scanf("%d",&ncases);
	while(ncases--){
		ans = 0;
		scanf("%d",&s);
		no = ne =  0;
		for(int i=0; i<s; i++){
			scanf("%d",&c);
			ans ^= c;
		}
		if(ans!=0)
			printf("Tom Wins\n");
		else
			printf("Hanks Wins\n");
	}
	return 0;
}
