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

int R, C;
char m[60][60];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main(){
	char c;
	int ncases, flag, x, y, o;
	flag=1;
	scanf("%d",&ncases);
	while(ncases--){
		if(flag) flag=0;
		else printf("\n");
		scanf("%d%d",&R,&C);
		scanf("%c",&c);
		f(i,0,R){
			f(j,0,C) scanf("%c",&m[i][j]);
			scanf("%c",&c);
		}
		scanf("%d%d",&x,&y);
		x--;
		y--;
		o = 0;
		while(scanf("%c",&c) && c!='Q'){
			switch(c){
				case 'R':
					o = (o+1+4)%4;
					break;
				case 'L':
					o = (o-1+4)%4;
					break;
				case 'F':
					if(m[x+dx[o]][y+dy[o]]!='*'){
						x += dx[o];
						y += dy[o];
					}
					break;
				default:
					break;
			}
		}	
		printf("%d %d ",x+1,y+1);
		switch(o){
			case 0:
				printf("N");
				break;
			case 1:
				printf("E");
				break;
			case 2:
				printf("S");
				break;
			case 3:
				printf("W");
				break;
			default:
				break;
			
		}
		printf("\n");
	}
	return 0;
}

