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
	int n, m, cont, flag, pa, pb, c;
	int p[8], arr[20][3];
	while(scanf("%d%d",&n,&m) && (n+m)){
		//printf("n:%d m:%d\n",n,m);
		cont = 0;
		f(i,0,n) p[i] = i;
		f(i,0,m) scanf("%d%d%d",&arr[i][0], &arr[i][1], &arr[i][2]); 
		do{
			flag = 1;
			/*
			f(i,0,n){
				printf("%d ",p[i]);
			}
			printf("\n");
			*/
			f(i,0,m){
				f(j,0,n){
					if(p[j]==arr[i][0])
						pa = j;	
					if(p[j]==arr[i][1])
						pb = j;
				}
				//printf(" pa %d pb %d\n",pa,pb);
				if(arr[i][2]>0){
					c = arr[i][2];
					if(abs(pa-pb)>c){
						flag = 0;
					}	
				}else{
					c = -arr[i][2];
					if(abs(pa-pb)<c){
						flag = 0;
					}
				}
				if(!flag) break;
			}	
			if(flag){
				cont++;
			}
		}while(next_permutation(p,p+n));
		printf("%d\n",cont);
	}
	return 0;
}
