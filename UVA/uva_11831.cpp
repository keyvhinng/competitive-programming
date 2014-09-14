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

char m[100][100];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main(){
	char c;
	int R, C, s, x, y, o, cont, nx, ny;
	while(scanf("%d%d%d",&R,&C,&s) && (R+C)){
		scanf("%c",&c);
		f(i,0,R){
			f(j,0,C){ 
				scanf("%c",&c);
				if(c=='N' || c=='S' || c=='L' || c=='O'){ 
					x = i;
					y = j;
					switch(c){
						case 'N':
							o = 0; break;
						case 'L':
							o = 1; break;
						case 'S':
						 	o = 2; break;
						case 'O':
							o = 3; break;	
						default:   
							break;
					}
				}
				m[i][j] = c;
			}
			scanf("%c",&c);
		}
		cont = 0;
		f(i,0,s){
			scanf("%c",&c);
			if(m[x][y]=='*'){
			   	cont++;
				m[x][y] = '.';
			}
			switch(c){
				case 'D':
					o = (o+1)%4;
					break;
				case 'E':
					o = (o+3)%4;
					break;
				case 'F':
					nx = x+dx[o];
					ny = y+dy[o];
					if(nx>=0 && nx<R && ny>=0 && ny<C &&m[nx][ny]!='#'){
						x += dx[o];
						y += dy[o];
					}
					break;
			}
		}
		if(m[x][y]=='*') cont++;
		printf("%d\n",cont);

	}
	return 0;
}

