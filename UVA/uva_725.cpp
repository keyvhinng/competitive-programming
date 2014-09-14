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
	int N, flag, ret;
	ret = 1;
	while(scanf("%d",&N) && N){
		if(ret){
			ret = 0;
		}else{
			printf("\n");
		}
		flag = 0;
		for(int fghij = 1234; fghij<=98765/N; fghij++){
			int abcde = fghij * N;

			int tmp, used = (fghij < 10000);
			tmp = abcde; while(tmp) { used |= 1 << (tmp%10); tmp/= 10;};
			tmp = fghij; while(tmp) { used |= 1 << (tmp%10); tmp/= 10;};
			if(used == (1<<10) - 1){
				flag = 1;
				if(abcde<10000){
					printf("0");
				}
				printf("%d / ",abcde);
				if(fghij<10000){
					printf("0");
				}
				printf("%d = ",fghij);
				printf("%d\n",N);
			}
		}
		if(!flag)
			printf("There are no solutions for %d.\n",N);
	}
	return 0;
}
