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

int m[5][5];

void run(int u, int l, VI p, vector<VI> used){
	vector<VI> v;
	VI np;
	if(l==8){
		for(int i=0; i<p.size(); i++){
			printf("%d",p[i]+1);
		}
		printf("\n");
	}
	else{
		for(int j=0; j<5; j++){
			if(m[u][j]){
				if(!used[u][j]){
					v.assign(5,VI());
					np = p;
					np.push_back(j);
					for(int i=0; i<5; i++)
						for(int j=0; j<5; j++)
							v[i].push_back(used[i][j]);
					v[u][j] = 1;
					v[j][u] = 1;
					run(j,l+1,np,v);
				}
			}
		}
	}
}

int main(){
	vector<VI> v;
	VI p;
	memset(m,0,sizeof(m));
	m[0][4] = m[4][0] = 1;
	m[4][3] = m[3][4] = 1;
	m[3][2] = m[2][3] = 1;
	m[2][1] = m[1][2] = 1;
	m[1][0] = m[0][1] = 1;
	m[4][2] = m[2][4] = 1;
	m[4][1] = m[1][4] = 1;
	m[0][2] = m[2][0] = 1;
	v.assign(5,VI());
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			v[i].push_back(0);
	p.push_back(0);
	run(0,0,p,v);	
	return 0;
}
