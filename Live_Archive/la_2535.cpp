//Live Archive 2535
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(){
	int N;
	int arr[31], sum, eq, k, suma, sumb;
	while(scanf("%d",&N) && N){
		eq = 0;
		sum = 0;
		k = 0;
		suma = 0;
		for(int i=0; i<N; i++){
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		//printf("total %d\n",sum);
		while(!eq && (k<N)){
			suma += arr[k];
		//	printf("suma %d\n",suma);
			sumb = sum - suma;
		//	printf("sumb %d\n",sumb);
			if(suma==sumb)
				eq = 1;
			k++;
		}
		if(eq)
			printf("Sam stops at position %d and Ella stops at position %d.\n",k,k+1);
		else{
			printf("No equal partitioning.\n");
		}
	}
	return 0;
}

