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

struct Car{
	char name[25];
	int a, b;
};

int main(){
	int q, ncases, n, ind, a, b, k, flag, cont;
	Car cars[10010];
	char name[25];
	scanf("%d",&ncases);
	f(z,0,ncases){
		if(z) printf("\n");
		scanf("%d",&n);
		f(i,0,n){
			scanf("%s %d %d",name, &a, &b);
			strcpy(cars[i].name,name);
			cars[i].a = a;
			cars[i].b = b;
		}
		scanf("%d",&q);
		f(i,0,q){
			scanf("%d",&k);
			cont = 0;
			f(j,0,n){
				if(cars[j].a<=k && cars[j].b>=k){
					ind = j;
					cont++;
				}
				if(cont>1){
					break;
				}
			}
			if(cont!=1){
				printf("UNDETERMINED\n");
			}else{
				printf("%s\n",cars[ind].name);
			}
		}
	}
	return 0;
}
