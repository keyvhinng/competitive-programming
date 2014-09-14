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
typedef pair<int, int> II;
typedef vector<II> VII;

struct Box{
	int ind;
	int dim[10];
};

int dp[30], prev[30];

int nest(Box a, Box b, int k){
	for(int i=0; i<k; i++)
		if(a.dim[i]>=b.dim[i]){
			return 0;
		}
	return 1;
}

void print(int ind, Box* box){
	if(prev[ind]!=-1)
		print(prev[ind],box);
	printf("%d ",box[ind].ind);
}

bool cmp(Box a, Box b){
	return a.dim[0] < b.dim[0];
}


int main(){
	int n, k;
	int max, ind_max;
	while(scanf("%d%d",&n,&k)==2){
		Box box[n];
		//read
		for(int i=0; i<n; i++){
			box[i].ind = i+1;
			for(int j=0; j<k; j++)
				scanf("%d",&box[i].dim[j]);
			sort(box[i].dim, box[i].dim+k);
		}
		sort(box,box+n,cmp);
		//init
		for(int i=0; i<n; i++){
			dp[i] = 1;
			prev[i] = -1;
		}
		//work
		max = 0;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(nest(box[i],box[j],k)){
					if(dp[i]+1>dp[j]){
						dp[j] = dp[i]+1;
						prev[j] = i;
					}
				}
			} 
		}
		for(int i=0; i<n; i++)
			if(dp[i]>max){
				max = dp[i];
				ind_max = i;
			}
		//print
		printf("%d\n",max);
		print(ind_max,box);	
		printf("\n");	
	}
	return 0;
}
