//UVA 514
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cmath>
#include <cassert>
#include <list>
#include <stack>
#include <bitset>
#include <functional>
#include <utility>
#include <sstream>
#include <cctype>
#include <ctime>

using namespace std;

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


typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

int main(){
	int n, b, flag, possible, e;
	stack<int> A;
	stack<int> sta;
	vector<int> B;
	while(scanf("%d",&n) && n){
		while(1){
			flag = 0;
			while(!A.empty()) A.pop();
			B.clear();
			while(!sta.empty()) sta.pop();
			for(int i=0; i<n; i++){
				scanf("%d",&b);
				//printf("leido %d i = %d\n",b,i);
				if(b==0){
					flag = 1;
					break;
				}
				B.pb(b);
			}
			if(flag)
				break;
			//work
			for(int i=n; i>0; i--)
				A.push(i);
			possible = 1;
			for(int i=0; i<B.size() && possible ;  ){
					e = B[i];
					//printf("analizing %d\n",e);
					if((!sta.empty()) && e==sta.top()){
						//printf("compare %d with %d\n",B.top(),sta.top());
						sta.pop();
						i++;
					}else{
						if(A.empty() || e < A.top()){
							possible = 0;
						}else{
							while((!A.empty()) && e != A.top()){
								sta.push(A.top());
								A.pop();
							}
							if(!A.empty()) {
								A.pop();
								i++;
							}
						}
					} 
			}
			if(possible) printf("Yes\n");
			else printf("No\n");
		}
		printf("\n");
	}
	return 0;
}
