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
	int k[20000], h[20000];
	int n, m, flag, sum, r, cont, p, q;
	while(scanf("%d%d",&n,&m)==2 && (n+m)){
		f(i,0,n) scanf("%d",&h[i]);
		f(i,0,m) scanf("%d",&k[i]);
		sort(h,h+n);
		sort(k,k+m);
		if(m<n){
			printf("Loowater is doomed!\n");	
		}else{
			sum = 0;
			cont = 0;
			p = 0;
			q = 0;
			sum = 0;
			while(p<n && q<m){
				while(h[p]>k[q] && q<m){
					q++;
				}		
				sum += k[q];
				//printf(" k[q] %d\n",k[q]);
				q++;
				p++;
				cont++;
				if(cont==n) break;
			}

			//printf("cont %d\n",cont);
			if(cont==n){
				printf("%d\n",sum);
			}else
				printf("Loowater is doomed!\n");
		}
	}
	return 0;
}

