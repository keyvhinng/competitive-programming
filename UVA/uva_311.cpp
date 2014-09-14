//UVA 10819
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

int N;
int W[101];
int V[101];

int value(int id, int remW){
	int ans, ans1, ans2, max;
	if(remW==0)
		return 0;
	if(id==N)
		return 0;
	if(W[id]>remW)
		ans = value(id+1,remW);
	else{
		max = -100000;
		ans1 = value(id+1, remW);
		ans2 = V[id] + value(id+1, remW-W[id]);
		if(ans1>ans2)
			max = ans1;
		else
			max = ans2;
	}
	return ans;
		
}

int main(){
	int s;
	while(scanf("%d %d",&s, &N)==2){
		if(s>2000){
			s += 200;
		}
		for(int i=0; i<N; i++){
			scanf("%d %d",&W[i], &V[i]);
		}
	}
	return 0;
}
