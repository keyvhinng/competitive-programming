#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <ctime>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i=x; i<y; i++)
#define FOR(it, A) for(typeof A.begin() it = A.begin(), it!=A.end(); it++)
#define quad(x) (x)*(x)
#define mp make_pair
#define clr(x,y) memset(x, y, sizeof x)
#define fst first
#define snd second

typedef pair<int, int>II;
typedef long long LL;
typedef long double LD;

int main(void){
	int a, b, n, num, cost;
	while(scanf("%d",&n) && n){
		priority_queue<int> pq;
		for(int i=0; i<n; i++){
			scanf("%d",&num);
			pq.push(-num);
		}
		cost = 0;
		while(pq.size()>1){
			a = pq.top();
			pq.pop();
			b = pq.top();
			pq.pop();
			cost += -(a+b);
			pq.push(a+b);
		}
		printf("%d\n",cost);
	}
	return 0;
}
