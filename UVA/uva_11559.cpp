//UVA 11559
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
	int N, B, H, W, p, pt, c;
	int min, tmin, w, posibT, posib;
	while(scanf("%d %d %d %d",&N, &B, &H, &W)==4){
		min = 20000000;
		posibT = 0;
		f(i,0,H){
			posib = 0;
			scanf("%d",&p);
			pt = p*N;
			f(j,0,W){
				scanf("%d",&c);
				if(c>=N){
					posib = 1;
				}
			}
			if(posib && pt<=B){
				posibT = 1;
				if(pt<min){
					min = pt;
				}
			}
		}
		if(posibT){
			printf("%d\n",min);
		}else{
			printf("stay home\n");
		}

	}
	return 0;
}
