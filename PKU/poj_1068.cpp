#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int t, n, i, j, p[32];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);		
		p[0]=0;
		for(i=1; i<=n; i++){
			scanf("%d",p+i);
		}
		for(i=1; i<=n; i++){
			for(j=i-1; p[i]-p[j]<i-j; --j);
			printf("%d ",i-j);
		}
		printf("\n");
	}
	return 0;
}
