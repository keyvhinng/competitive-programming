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
#include <iomanip>
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
#define sz size

using namespace std;

char m[100][100];
int dx[] = {0,1};
int dy[] = {1,0};

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int ncases, N, cont, nx, ny, dir, tx, ty, flag;
	char c;
	scanf("%d",&ncases);
	f(nc,1,ncases+1){
		printf("Case %d: ",nc);
		scanf("%d",&N);
		scanf("%c",&c);
		f(i,0,N){
			f(j,0,N){
				scanf("%c",&m[i][j]);
			}
			scanf("%c",&c);
		}
		cont = 0;
		f(i,0,N){
			f(j,0,N){
				if(m[i][j]!='.'){
					flag = 0;
					dir = -1;
					f(k,0,2){
						nx = i + dx[k];
						ny = j + dy[k];
						if(nx>=0 && nx<N && ny>=0 && ny<N && m[nx][ny]!='.'){
							dir = k;
						}	
					}
					tx = i;
					ty = j;	
					if(dir==-1){ 
						if(m[i][j]=='x') flag=1;
						m[i][j]='.';
					}
					while(tx>=0 && tx<N && ty>=0 && ty<N && m[tx][ty]!='.'){ 
						if(m[tx][ty]=='x') flag=1;
						m[tx][ty] = '.';
						tx += dx[dir];
						ty += dy[dir];
					}
					if(flag) cont++;
				}
			}
		}
		printf("%d\n",cont);
	}
	return 0;
}

