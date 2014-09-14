#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n, ncase;
	ncase = 1;
	while(scanf("%d",&n) && n){
		printf("Case %d:",ncase++); 
		if( (n-1)%4==0 || (n-2)%4==0){
			printf(" -1\n");
			continue;
		}
		int change = n/2;
		int val = 1, p =1;
		vector<int> res, bres;
		for(int i=n; i>=0; i--){
			res.push_back(val);
			val = p ? (val+i) : (val-i);
			p = 1 - p;
			if(i==change+1) i--;
		}
		for(int i =1; i<res.size(); i++){
			bres.push_back(res[i]);
		}
		bres.push_back(1);
		reverse(bres.begin(),bres.end());
		for(int i=0; i<bres.size(); i++){
			printf(" %d",bres[i]);
		}
		printf("\n");
	}
}
