//SPOJ RPS
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(){
	int n, m, cont, ncase;
	int arr[21], arr2[21], mod[21], div2[21];
	ncase = 1;
	while(scanf("%d %d",&n, &m) && (n+m!=0)){
		for(int i=0; i<n; i++){
			arr[i] = 0;
			mod[i] = 0;
			div2[i] = 0;
		}	
		arr[0] = n;
		cont = 0;
		while(arr[m]==0){
			cont++;

			//printf("cont %d\n",cont);
			//for(int x=0; x<n; x++){
			//	printf("%d ",arr[x]);
			//}
			//printf("\n");

			for(int x=0; x<n; x++){
				mod[x] = arr[x] % 2;
				div2[x] = arr[x] / 2;
			}
			arr2[0] = 0;
			for(int x=0; x<n; x++){
				arr2[0] += div2[x];
			}
			arr2[0] += mod[0];
			for(int x=1; x<n; x++){
				arr2[x] = div2[x-1] + mod[x];
			}
			for(int x=0; x<n; x++){
				arr[x] = arr2[x];
			}
		}
		printf("Case %d: %d\n",ncase,cont);
		ncase++;
	}
	return 0;
}
