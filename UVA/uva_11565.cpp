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
	int a, b, c, ncases;
	scanf("%d",&ncases);
	while(ncases--){
		scanf("%d%d%d",&a,&b,&c);
		bool sol = false;
		for(int x =-22; x<22 && !sol; x++){
			for(int y=-100; y<101 && !sol; y++){
				for(int z=-100; z<101 && !sol; z++){
					if(y!=x && z!=x && z!=y &&
							x+y+z==a && x*y*z==b && x*x+y*y+z*z==c){
						printf("%d %d %d\n",x, y, z);
						sol = true;
					}
				}
			}
		}
		if(!sol){
			printf("No solution.\n");
		}
	}
	return 0;
}
