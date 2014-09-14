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
#define rall(v) (v).rebing(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i=x; i<y; i++)
#define FOR(it, A) for(typeof A.begin(); it!=A.end(); it++)
#define quad(x) (x)*(x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second

using namespace std;

int main(){
	int N, a, b, c, d, e, f;
	int arr[13], flag;
	flag = 1;
	while(scanf("%d",&N) && N){
		if(flag){
			flag = 0;
		}else{
			printf("\n");
		}
		for(int i=0; i<N; i++){
			scanf("%d",&arr[i]);
		}
		f(i,0,N){
			f(j,i+1,N){
				f(k,j+1,N){
					f(l,k+1,N){
						f(m,l+1,N){
							f(n,m+1,N){
								printf("%d %d %d %d %d %d\n",arr[i], arr[j], arr[k], arr[l], arr[m], arr[n]);	
							}	
						}
					}
				}	
			}
		}
	}
	return 0;
}
