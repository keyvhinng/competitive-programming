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

int n, ans;
int adjMat[110][110];
vector<int> primes;
vector<int> vans;

bool check(vector<int> v, int k){
	if(v.size()){
		f(i,0,v.size()){
			if(adjMat[i][k] && v[i]) 
				return false;
		}
	}
	return true;
}

void backtrack(vector<int> v, int r){
	/*
	f(k,0,v.size()){
		printf(" %d",v[k]);
	}
	printf("\n");
	*/
	int myans;
	if(r==n){
		myans = 0;
		f(i,0,n){
			myans += v[i];
		}
		if(myans > ans){
			vans.assign(n,0);
			//printf("vans %d\n",vans.size());
			//printf("v %d\n",v.size());
			f(j,0,n){
				vans[j] = v[j];
			}
			ans = myans;
		}
		return;
	}
	if(check(v, r)){
		v.pb(1);
		backtrack(v,r+1);	
		v.erase(v.begin()+r);
	}
	v.pb(0);
	backtrack(v,r+1);
}

int main(){
	int cont, ncases, m, flag, nc, u, v;
	scanf("%d",&ncases);
	vector<int> ve;
	while(ncases--){
		ans = 0;
		scanf("%d%d",&n,&m);
		clr(adjMat,0);
		f(i,0,m){
			scanf("%d%d",&u,&v);
			u--;
			v--;
			adjMat[u][v] = 1;
			adjMat[v][u] = 1;
		}
		ve.clear();
		vans.clear();
		backtrack(ve, 0);
		printf("%d\n",ans);
		flag = 1;
		f(i,0,n){
			if(vans[i]){
				if(flag){
					flag = 0;
				}else{
					printf(" ");
				}
				printf("%d",i+1);
			}

		}
		printf("\n");
	}
	return 0;
}
