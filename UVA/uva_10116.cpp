#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <cmath>
#include <algorithm>
#include <ctime>

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

using namespace std;

char m[10][10];
char v[10][10];
int cont, ok, ns, nsc, R, C;

void run(int x, int y){
	int dx, dy;
	char c;
	if(x<0 || x>=R || y<0 || y>=C){
		ok = 1;
		return;
	}
	v[x][y]++;
	c  = m[x][y];
	switch(c){
		case 'N':
			dx = -1;
			dy = 0;
			break;
		case 'S':
			dx = 1;
			dy = 0;
			break;
		case 'E':
			dx = 0;
			dy = 1;
			break;
		case 'W':
			dx = 0;
			dy = -1;
			break;
	}
	if(v[x][y]==1){
		ns++;
		run(x+dx,y+dy);
	}else if(v[x][y]==2){
		nsc++;
		run(x+dx,y+dy);
	}
}

int main(){
	char c;
	int col;
	while(scanf("%d%d%d",&R,&C,&col) && (R+C)){
		ns = nsc = 0;
		ok = 0;
		clr(v,0);
		cont = 0;
		scanf("%c",&c);
		f(i,0,R){
			f(j,0,C) scanf("%c",&m[i][j]);
			scanf("%c",&c);
		}
		col--;
		run(0,col);
		if(ok){
			printf("%d step(s) to exit\n",ns);
		}else{
			printf("%d step(s) before a loop of %d step(s)\n",ns-nsc,nsc);
		}
	}
	return 0;
}
