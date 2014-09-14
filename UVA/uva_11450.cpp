//UVA 11450 Wedding Shopping
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
	int i, j, l, TC, M, C, price[25][25];
	bool can_reach[210][25];

	scanf("%d", &TC);
	while(TC--){
		scanf("%d %d", &M, &C);
		for(i = 0; i < C; i++){
			scanf("%d", &price[i][0]);
			for (j=1; j<=price[i][0]; j++){
				scanf("%d", &price[i][j]);
			}
		}

		memset(can_reach, false, sizeof can_reach);
		for(i=1; i<=price[0][0]; i++){
			if(M-price[0][i]>=0)
				can_reach[M-price[0][i]][0] = true;
		}

		for(j=1; j<C; j++){
			for(i=0; i<M; i++){
				if(can_reach[i][j-1])
					for(l=1; l<=price[j][0]; l++){
						if(i-price[j][l]>=0){
							can_reach[i-price[j][l]][j] = true;
						}
					}
			}
		}

		for(i = 0; i<=M && !can_reach[i][C-1]; i++);
		if(i==M+1)
			printf("no solution\n");
		else
			printf("%d\n",M-i);
	}
	return 0;
}
