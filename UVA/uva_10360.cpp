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

int main(){
	int max, ncases, d, n, x, y, z, s, nx, ny;
	scanf("%d",&ncases);
	while(ncases--){
		int killed[1024][1024];
		clr(killed,0);
		scanf("%d",&d);
		scanf("%d",&n);
		f(i,0,n){
			scanf("%d%d%d",&x,&y,&z);
			x--;
			y--;
			f(j,x-d,x+d+1){
				f(k,y-d,y+d+1){
					nx = j;
					ny = k;
					if(nx>=0 && nx<1024 && ny>=0 && ny<1024 ){
						killed[nx][ny] += z;
					}
				}
			}
		}
		max = 0;
		f(i,0,1024){
			f(j,0,1024){
				if(killed[i][j]>max){
					max = killed[i][j];
					x = i + 1;
					y = j + 1;
				}	
			}
		}
		printf("%d %d %d\n",x,y,max);
	}
	return 0;
}
