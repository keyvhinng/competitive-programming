#include <cstdio>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int ans, curr, ncases, n, num, max, ini, maxini;
	map<int, int> m;
	scanf("%d",&ncases);
	for(int i=0; i<ncases; i++){
		scanf("%d",&n);
		//printf("n %d\n",n);
		m.clear();
		ini = 0;
		ans = -1;
		for(int j=1; j<=n; j++){
			scanf("%d",&num);
			//printf("num %d",num);
			m[num];
			if(m[num]!=0){
				if(ini<m[num]){
					ini = m[num];
				}
			}
			m[num] = j;
			curr = j - ini;
			//printf(" curr %d\n",curr);
			if(ans<curr){
				ans = curr;
			}
		}
		printf("%d\n",ans);
	}
}
