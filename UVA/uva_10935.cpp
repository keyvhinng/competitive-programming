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
	int n, flag, c;
	while(scanf("%d",&n) && n){
		flag = 0;
		queue<int> q;
		for(int i=1; i<=n; i++){
			q.push(i);
		}
		if(q.size()==1){
			printf("Discarded cards:\n");
			printf("Remaining card: 1\n");
		}else{
			printf("Discarded cards: ");
			while(q.size()>1){
				if(!flag){
					flag = 1;
				}else{
					printf(", ");
				}
				printf("%d",q.front());
				q.pop();
				c = q.front();
				q.pop();
				q.push(c);
			}
			printf("\n");
			printf("Remaining card: %d\n",q.front());
		}
	}

	return 0;
}
