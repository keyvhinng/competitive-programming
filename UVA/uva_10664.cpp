//UVA 10664
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
typedef pair<int, int> PII;
typedef vector<PII> VPII;

int W[20];
int DP[201][21];
int nsuit;

int run(int w, int i){
//	printf("w %d i %d\n",w,i);
	if(DP[w][i]!=-1){
		return DP[w][i];
	}
	if(w==W[i]){
		return 1;
	}
	if(i<nsuit-1){	
		if(w>W[i]){
			if(run(w-W[i],i+1))
				return DP[w][i] = 1;
		}	
		if(run(w,i+1))
			return DP[w][i] = 1;
	}
	return DP[w][i] = 0;
}

int main(){
	char c;
	int ncases, w, tw;
	scanf("%d",&ncases);
	scanf("%c",&c);
	while(ncases--){
		nsuit = 0;
		tw = 0;
		while(1){
			scanf("%d",&w);
			W[nsuit] = w;
			tw += w;
			scanf("%c",&c);
			nsuit++;
			if(c=='\n'){
				break;
			}
		}
		if((tw%2==1)){
			printf("NO\n");
		}else{
			//printf("nsuit %d\n",nsuit);
			for(int i=0; i<=tw/2; i++){
				for(int j=0; j<=nsuit; j++){
					DP[i][j] = -1;
				}
			}
			//printf("tw %d\n",tw);
			if(run(tw/2,0)){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
	return 0;
}
